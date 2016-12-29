#include "corewar.h"

static int	is_useless(unsigned char c)
{
	if (c == 1 || c == 9 || c == 12 || c == 11)
		return (0);
	else
		return (1);
}

int main(int ac, char **av)
{
	t_cw		cw;
	t_list		*l;
	t_process	*p;
	long long	turn;

	cw = cw_init(ac, av);
	turn = 0;
	initscr();
	noecho();
	curs_set(FALSE);
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_WHITE, COLOR_BLUE);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLUE);
	/*
	**	TODO
	**
	**	Systeme qui parse les parametre et qui initialise les premiers processus
	**	voici trois initialisation faite en dur
	*/
	bytecode_read(&cw, av[1], 0);
	process_add(&cw, -1, 0);
	bytecode_read(&cw, av[2], MEM_SIZE / 3);
	process_add(&cw, -2, MEM_SIZE / 3);
	bytecode_read(&cw, av[3], (MEM_SIZE / 3) * 2);
	process_add(&cw, -3, (MEM_SIZE / 3) * 2);
	/*
	**	END TODO 
	*/
	while (cw.process)
	{
		mvprintw(0, 0, "TURN: %lld NB_PROCESS: %lld\n", turn, cw.nb_process);
		board_print(cw);
		l = cw.process;
		while (l)
		{
			p = (t_process*)l->content;
			if (is_useless(cw.board[p->pc]))
				p->pc++;
			else
				exec(&cw, p, cw.fct_tab[cw.board[p->pc]]);
			if (p->pc == MEM_SIZE)
				p->pc = 0;
			l = l->next;
		}
		refresh();
		++turn;
	}
	endwin();
	(cw.board) ? free(cw.board) : (void)0;
	return (1);
}
