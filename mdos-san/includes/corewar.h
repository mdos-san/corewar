#ifndef COREWAR_H
# define COREWAR_H

# include <stdlib.h>

# include "op.h"
# include "libftprintf.h"

# define NB_COL	84

typedef	struct		s_cw
{
	unsigned char	*board;


}					t_cw;

void	board_print(t_cw cw);

#endif