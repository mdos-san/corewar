#include "corewar.h"

void	dump(t_cw *cw)
{
	int	i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (i % 32 == 0)
			ft_printf("0x%.4x: ", i);
		ft_printf("%.2x ", cw->board[i]);
		if ((i + 1) % 32 == 0)	
			ft_putchar('\n');
		++i;
	}
}

int main(int ac, char **av)
{
	t_cw		cw;
	t_list		*l;
	t_process	*p;
	long long	turn;
	long long	check;
	t_list	*prev;
	long	nb_live;
	int		max_check;
	int		death;

	cw = cw_init(ac, av);
	turn = 0;
	check = 0;
	max_check = 0;
	death = 0;
	cw_parse(&cw);
	while (cw.process)
	{
		if (cw.f_dump != -1 && turn == cw.f_dump - 1)
			break ;
		if (check == cw.cycle_to_die)
		{
			death = 1;
			check = 0;
			nb_live = 0;
			prev = NULL;
		}
	/*	{
			l = cw.process;
			while (l)
			{
				p = (t_process*)l->content;
				if (p->nb_live > 0)
				{
					nb_live += p->nb_live;
					prev = l;
				}
				else
				{
					if (prev != NULL)
						prev->next = l->next;
					else
						cw.process = l->next;
				}
				p->nb_live = 0;
				l = l->next;
			}
			if (nb_live >= NBR_LIVE || max_check == MAX_CHECKS)
			{
				cw.cycle_to_die -= CYCLE_DELTA;
				max_check = 0;
			}
			else
				max_check++;
			check = 0;
		}
	*/	if (cw.cycle_to_die <= 0)
			break ;
		if (cw.f_v == 1)
		{
			attron(COLOR_PAIR(1));
			mvprintw(0, 0, "TURN: %lld NB_PROCESS: %lld, CYCLE_TO_DIE: %d, last_check_nb_live: %d, max_check: %d\n", turn, cw.nb_process, cw.cycle_to_die, nb_live, max_check);
			board_print(cw);
			refresh();
		}
		l = cw.process;
		while (l)
		{
			p = (t_process*)l->content;
			exec(&cw, p, cw.fct_tab[cw.board[p->pc]]);
			if (death == 1)
			{
				if (p->nb_live > 0)
				{
					nb_live += p->nb_live;
					prev = l;
				}
				else
				{
					if (prev != NULL)
						prev->next = l->next;
					else
						cw.process = l->next;
				}
				p->nb_live = 0;
				
			}
			if (p->pc == MEM_SIZE)
				p->pc = 0;
			l = l->next;
		}
		if (death)
		{
			if (nb_live >= NBR_LIVE || max_check == MAX_CHECKS)
			{
				cw.cycle_to_die -= CYCLE_DELTA;
				max_check = 0;
			}
			else
				max_check++;
			death = 0;
		}
		++turn;
		++check;
	}
	if (cw.f_v == 1)
		endwin();
	if (cw.f_dump != -1)
		dump(&cw);
	ft_printf("Ended in turn %d\n", turn);
	(cw.board) ? free(cw.board) : (void)0;
	return (1);
}
