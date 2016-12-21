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
# define NB_COL	64

/*
**|	struct s_process
**|
**|	Permet de stoker toute les infos relative a un processus
**|
**|	nb_champ: numero du champion associé
**|	pc: index de l octet lu par rapport au debut de board
**|	nb_process: numero du processus
**|	is_waiting: permet de savoir si le process est actuellement en attente
**|	waiting_turn: nombre de tour restant a attendre pour executer la fonction pointé par pc.
**|	
*/

typedef struct		s_process
{
	int				nb_champ;
	int				pc;
	long long		nb_process;
	int				is_waiting;
	int				waiting_turn;
	int				r[REG_NUMBER];
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
**|	nb_process: nombre de processus actif dans la vm
**|	process: liste chainnée contenant des element t_process
**|	fct_tab: tableau de pointeur sur fonction utilise pour les fonctions asm gerée. (add, zjmp, sti, ...)
**|
*/

typedef	struct		s_cw
{
	char			debug;
	int				ac;
	char			**av;
	unsigned char	*board;
	long long		nb_process;
	t_list			*process;
	void			(*fct_tab[256])(struct s_cw*, t_process*);
}					t_cw;

t_cw	cw_init(int ac, char **av);
void	board_print(t_cw cw);
int		bytecode_read(t_cw *cw, char *file, int	index);
void	process_add(t_cw *cw, int champ, int pc);
void	live(t_cw *cw, t_process *p);
void	zjmp(t_cw *cw, t_process *p);
void	frk(t_cw *cw, t_process *p);

#endif