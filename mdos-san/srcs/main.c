#include "corewar.h"

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

	cw = cw_init(ac, av);
	turn = 0;
	check = 0;
	max_check = 0;
	initscr();
	noecho();
	curs_set(FALSE);
	start_color();
	init_pair(42, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(1 + 4, COLOR_GREEN, COLOR_CYAN);
	init_pair(2 + 4, COLOR_BLUE, COLOR_CYAN);
	init_pair(3 + 4, COLOR_RED, COLOR_CYAN);
	init_pair(4 + 4, COLOR_YELLOW, COLOR_CYAN);
	init_pair(42 + 4, COLOR_WHITE, COLOR_CYAN);
	/*
	**	TODO
	**
	**	Systeme qui parse les parametre et qui initialise les premiers processus
	**	voici trois initialisation faite en dur
	*/
	cw_parse(&cw);
	/*
	**	END TODO 
	*/
	while (cw.process)
	{
//		if (turn > 4700)
//		usleep(100000);
		/* Check pour diminuer cycle_to_die */
		if (check == cw.cycle_to_die)
		{
			nb_live = 0;
			l = cw.process;
			prev = NULL;
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
		if (cw.cycle_to_die <= 0)
			break ;
		/* END */
		attron(COLOR_PAIR(1));
		mvprintw(0, 0, "TURN: %lld NB_PROCESS: %lld, CYCLE_TO_DIE: %d, last_check_nb_live: %d, max_check: %d\n", turn, cw.nb_process, cw.cycle_to_die, nb_live, max_check);
		board_print(cw);
		l = cw.process;
		while (l)
		{
			p = (t_process*)l->content;
			exec(&cw, p, cw.fct_tab[cw.board[p->pc]]);
			if (p->pc == MEM_SIZE)
				p->pc = 0;
			l = l->next;
		}
		refresh();
		++turn;
		++check;
	}
	endwin();
	ft_printf("Ended in turn %d\n", turn);
	(cw.board) ? free(cw.board) : (void)0;
	return (1);
}
