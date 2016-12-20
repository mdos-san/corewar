#ifndef COREWAR_H
# define COREWAR_H

# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# include "op.h"
# include "libftprintf.h"

# define NB_COL	84

typedef	struct		s_cw
{
	int				ac;
	char			**av;
	unsigned char	*board;

}					t_cw;

void	board_print(t_cw cw);
int		bytecode_read(t_cw *cw);

#endif