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
	mtrace();
	t_cw		cw;
	t_process	*l;
	long long	turn;
	long long	check;
	t_process	*prev;
	long		nb_live;
	int			max_check;

	cw = cw_init(ac, av);
	turn = 0;
	check = 0;
	max_check = 0;
	cw_parse(&cw);
	nb_live = 0;
	while (cw.process)
	{
		if (cw.f_dump != -1 && turn == cw.f_dump - 1)
			break ;
		if (check == cw.cycle_to_die)
		{
			l = cw.process;
			nb_live = 0;
			prev = NULL;
			ft_printf("turn: %d\n", turn);
			while (l)
			{
				if (l->nb_live > 0)
				{
					nb_live += l->nb_live;
					prev = l;
				}
				else
				{
					if (prev != NULL)
						prev->next = l->next;
					else
						cw.process = l->next;
				}
				l->nb_live = 0;
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
		if (cw.cycle_to_die <= 0)
			break ;
		if (cw.f_v == 1)
		{
			attron(COLOR_PAIR(1));
			mvprintw(0, 0, "TURN: %lld NB_PROCESS: %lld, CYCLE_TO_DIE: %d, last_check_nb_live: %d, max_check: %d\n", turn, cw.nb_process, cw.cycle_to_die, nb_live, max_check);
			board_print(cw);
			refresh();
		}
		l = cw.process;
		ft_printf("start: %d\n", turn);
		while (l)
		{
			if (l->is_waiting == 0)
			{
				l->is_waiting = 1;
				l->waiting_turn = turn + get_turn(cw.board[l->pc]);
			} 
			else if (l->waiting_turn == turn)
			{
				cw.fct_tab[cw.board[l->pc]](&cw, l);
				l->is_waiting = 0;
			}
			l = l->next;
		}
		ft_printf("end\n");
		++turn;
		++check;
	}
	if (cw.f_v == 1)
		endwin();
	if (cw.f_dump != -1)
		dump(&cw);
	ft_printf("Ended in turn %d\n", turn);
	(cw.board) ? free(cw.board) : (void)0;
	muntrace();
	return (1);
}
/*
int main()
{
	t_process *p;
	t_process *l;
	int			i = 0;

	p = NULL;
	while (i < 21000)
	{
		process_new(&p, 0, 0, 0);
		++i;
	}
	i = 0;
	while (i < 21000)	
	{
		l = p;
		while (l)
		{
			if (l->waiting_turn >= 0)
			l->waiting_turn++;
			l = l->next;
		}
		++i;
	}
	return (0);
}*/
