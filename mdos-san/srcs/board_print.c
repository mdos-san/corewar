#include "corewar.h"

void	board_print(t_cw cw)
{
	int		i;
	t_list	*l;

	i = 0;
	while (i < MEM_SIZE)
	{
		l = cw.process;
		if (cw.board[i] > 0)
			attron(COLOR_PAIR(3));
		else
			attron(COLOR_PAIR(1));
		while (l)
		{
			if (((t_process*)(l->content))->pc == i)
			{
				if (cw.board[i] > 0)
					attron(COLOR_PAIR(4));
				else
					attron(COLOR_PAIR(2));
				break ;
			}
			l = l->next;
		}
		printw("%.2x", (int)cw.board[i]);
		if ((i + 1) % NB_COL  == 0)
			printw("\n");
		++i;
	}
	(void)l;
}
