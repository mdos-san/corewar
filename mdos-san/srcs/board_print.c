#include "corewar.h"

void	board_print(t_cw cw)
{
	int		i;
	t_list	*l;

	i = 0;
	while (i < MEM_SIZE)
	{
		l = cw.process;
		ft_printf("\033[40m");
		while (l)
		{
			if (((t_process*)(l->content))->pc == i)
			{
				ft_printf("\033[44m");
				break ;
			}
			l = l->next;
		}
		if (cw.board[i] > 0)
			ft_printf("\033[32m%.2x ", (int)cw.board[i]);
		else
			ft_printf("\033[37m%.2x ", (int)cw.board[i]);
		if ((i + 1) % NB_COL  == 0)
			ft_putchar('\n');
		++i;
	}
}