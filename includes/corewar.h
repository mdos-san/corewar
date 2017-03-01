#ifndef COREWAR_H
# define COREWAR_H

# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <ncurses.h>

# include "op.h"
# include "libftprintf.h"

# define DEBUG 1
# define NB_COL	64

typedef struct		s_ocp
{
	char			one[3];
	char			two[3];
	char			three[3];
}					t_ocp;

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

typedef struct			s_process
{
	struct s_process	*next;
	long long			nb_process;
	int					nb_champ;
	int					pc;
	int					is_waiting;
	int					waiting_turn;
	int					r[REG_NUMBER];
	int					nb_live;
	int					carry;
	int					*p_one;
	int					*p_two;
	int					*p_three;
	int					one;
	int					two;
	int					three;
	int					color_nb;
	int					fct;
}						t_process;

typedef struct		s_champ
{
	char			*path;
	header_t		h;
	int				padding;
}					t_champ;

/*
**|	struct	s_cw
**|
**|	Structure principale de la vm.
**|
**|
**|	ac:	nombre d'argument passé en parametre
**|	av: les arguments passé en parametre
**|	board:	zone memoire alloué pour le 'jeu' les champions seront chargés dedans
**|	nb_process: nombre de processus actif dans la vm
**|	process: liste chainnée contenant des elements t_process
**|	fct_tab: tableau de pointeur sur fonction utilise pour les fonctions asm gerée. (add, zjmp, sti, ...)
**|
*/

typedef	struct		s_cw
{
	char			**av;
	unsigned char	*board;
	unsigned char	*board_color;
	unsigned char	*board_ptr;
	t_process		*process;
	t_process		*ap;
	void			(*fct_tab[256])(struct s_cw*, t_process*);
	t_champ			champs[4];
	int				nb_process;
	int				ac;
	int				cycle_to_die;
	int				f_v;
	int				f_a;
	int				f_verbose;
	int				f_dump;
	int				f_d;
	int				asm_i;
	int				asm_tmp;
	t_ocp			asm_ocp;
	char			debug;
	short			padding;
	int				idx;
	int				param_error;
	int				normal;
	long long		ins;
	int				nb_readed;
}					t_cw;

t_cw		cw_init(int ac, char **av);
void		cw_parse(t_cw *cw);
void		board_print(t_cw *cw);
void		verbose_print(t_cw *cw, int i, int start, int end);
int			bytecode_read(t_cw *cw, char *file, int	index, int color_nb);
t_process	*process_new(t_process **act, int champ, int pc, int color_nb);
int			process_count(t_process *l);
void		board_to_int(t_cw *cw, int *value, int offset);
void		int_to_board(t_cw *cw, int *value, int offset);
void		live(t_cw *cw, t_process *p);
void		ld(t_cw *cw, t_process *p);
void		st(t_cw *cw, t_process *p);
void		add(t_cw *cw, t_process *p);
void		sub(t_cw *cw, t_process *p);
void		and(t_cw *cw, t_process *p);
void		or(t_cw *cw, t_process *p);
void		xor(t_cw *cw, t_process *p);
void		zjmp(t_cw *cw, t_process *p);
void		sti(t_cw *cw, t_process *p);
void		ldi(t_cw *cw, t_process *p);
void		frk(t_cw *cw, t_process *p);
void		lld(t_cw *cw, t_process *p);
void		lldi(t_cw *cw, t_process *p);
void		lfrk(t_cw *cw, t_process *p);
void		aff(t_cw *cw, t_process *p);
t_ocp		ocp_get(unsigned char ocp);
void		ocp_parse(t_cw *cw, t_process *p, t_ocp ocp, int dir_two, int get_index);
int			get_turn(unsigned char c);
int			mod(int a, int b);
int			idx_mod(int a);

#endif
