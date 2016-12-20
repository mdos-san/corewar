#include "corewar.h"

void	board_print(t_cw cw)
{
	int	i;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("%.2x ", (int)cw.board[i]);
		if ((i + 1) % NB_COL  == 0)
			ft_putchar('\n');
		++i;
	}
}