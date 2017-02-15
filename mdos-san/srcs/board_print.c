#include "corewar.h"

void	board_print(t_cw cw)
{
	int		i;
	t_process	*l;
	int		is_readed;

	i = 0;
	while (i < MEM_SIZE)
	{
		is_readed = 0;
		l = cw.process;
		if (cw.board_color[i] == 0)
			attron(COLOR_PAIR(42));
		else
			attron(COLOR_PAIR((int)cw.board_color[i]));
		while (l)
		{
			if (l->pc == i)
			{
				is_readed = 1;
				break ;
			}
			l = l->next;
		}
		if (cw.board_color[i] != 0)
			attron(COLOR_PAIR((int)cw.board_color[i] + ((is_readed) ? 4 : 0)));
		else if (is_readed)
			attron(COLOR_PAIR(46));
		printw("%.2x ", (int)cw.board[i]);
		if ((i + 1) % NB_COL  == 0)
			printw("\n");
		++i;
	}
	(void)l;
}
