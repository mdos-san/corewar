#ifndef COREWAR_H
# define COREWAR_H

# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# include "op.h"
# include "libftprintf.h"

# define DEBUG 1
# define NB_COL	84

/*
**|	struct s_process
**|
**|	Permet de stoker toute les infos relative a un processus
**|
**|	nb_champ: numero du champion associé
**|	pc: pointeur sur la zone lu par le processus
**| 
**|
*/

typedef struct		s_process
{
	int				nb_champ;
	unsigned char	*pc;
}					t_process;

/*
**|	struct	s_cw
**|
**|	Structure principale de la vm.
**|
**|
**|	ac:	nombre d'argument passé en parametre
**|	av: les arguments passé en parametre
**|	board:	zone memoire alloué pour le 'jeu' les champ seront chargé dedans
**|
**|
**|
*/

typedef	struct		s_cw
{
	char			debug;
	int				ac;
	char			**av;
	unsigned char	*board;
	t_list			*process;
}					t_cw;

void	board_print(t_cw cw);
int		bytecode_read(t_cw *cw);

#endif