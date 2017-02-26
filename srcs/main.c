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

void	d(t_cw *cw)
{
	int	i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0)
			ft_printf("0x%.4x : ", i);
		ft_printf("%.2x ", cw->board[i]);
		if ((i + 1) % 64 == 0)	
			ft_putchar('\n');
		++i;
	}
}

static void	die(t_cw *cw, int *check)
{
	static int	max_check = 0;
	int			nb_live;
	t_process	*l;
	t_process	*prev;

	l = cw->process;
	nb_live = 0;
	prev = NULL;
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
			{
				prev->next = l->next;
				free(l);
				l = prev;
			}
			else
			{
				cw->process = l->next;
				free(l);
				if (process_count(cw->process) == 0)
					exit (0);
				l = cw->process;
			}
		}
		l->nb_live = 0;
		l = l->next;
	}
	if (nb_live >= NBR_LIVE || max_check == MAX_CHECKS)
	{
		cw->cycle_to_die -= CYCLE_DELTA;
		max_check = 0;
	}
	else
		max_check++;
	*check = 0;
}

static void	exec_turn(t_cw *cw, int *turn)
{
	t_process *l;

	l = cw->process;
	while (l)
	{
		if (l->is_waiting == 0)
		{
			l->is_waiting = 1;
			l->waiting_turn = *turn + get_turn(cw->board[l->pc]) - 1;
		} 
		else if (l->waiting_turn == *turn)
		{
			cw->fct_tab[cw->board[l->pc]](cw, l);
			l->is_waiting = 0;
		}
		l = l->next;
	}
}

int main(int ac, char **av)
{
	t_cw		cw;
	int			turn;
	int			check;

	cw = cw_init(ac, av);
	turn = 0;
	check = 0;
	cw_parse(&cw);
	while (cw.process)
	{
		if (turn == 15000)
			sleep(100);
		if (turn == cw.f_dump || turn == cw.f_d)
			break ;
		if (check == cw.cycle_to_die)
			die(&cw, &check);
		if (cw.cycle_to_die <= 0)
			break ;
		if (cw.f_v == 1)
		{
			attron(COLOR_PAIR(1));
			mvprintw(0, 0, "Turn: %d, Process: %d\n", turn, process_count(cw.process));
			board_print(cw);
			refresh();
		}
		exec_turn(&cw, &turn);
		++turn;
		++check;
	}
	if (cw.f_v == 1)
		endwin();
	if (cw.f_d != -1)
		d(&cw);
	else if (cw.f_dump != -1)
		dump(&cw);
//	ft_printf("Ended in turn %d\n", turn);
	(cw.board) ? free(cw.board) : (void)0;
	return (1);
}
