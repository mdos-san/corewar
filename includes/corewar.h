/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 11:38:18 by mdos-san          #+#    #+#             */
/*   Updated: 2017/03/03 14:28:05 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

typedef struct			s_ocp
{
	char				one[3];
	char				two[3];
	char				three[3];
}						t_ocp;

/*
**|	struct s_process
**|
**|	Permet de stoker toute les infos relative a un processus
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

typedef struct			s_champ
{
	char				*path;
	t_header			h;
	int					number;
	int					last_live;
}						t_champ;

/*
**|	struct	s_cw
**|
**|	Structure principale de la vm.
**|
*/

typedef	struct			s_cw
{
	char				**av;
	unsigned char		*board;
	unsigned char		*board_color;
	unsigned char		*board_ptr;
	t_process			*process;
	t_process			*ap;
	void				(*fct_tab[256])(struct s_cw*, t_process*);
	t_champ				champs[4];
	int					nb_process;
	int					ac;
	int					turn;
	int					check;
	int					cycle_to_die;
	int					f_v;
	int					f_a;
	int					f_verbose;
	int					f_dump;
	int					f_d;
	int					asm_i;
	int					asm_tmp;
	t_ocp				asm_ocp;
	char				debug;
	int					idx;
	int					param_error;
	int					normal;
	long long			ins;
	int					nb_readed;
	int					nb_param;
	int					fd;
	char				buf[1];
	t_header			*h;
	int					len_offset;
	int					index;
	int					color_nb;
}						t_cw;

t_cw					cw_init(int ac, char **av);
void					cw_parse(t_cw *cw);
void					board_print(t_cw *cw);
void					verbose_print(t_cw *cw, int i, int start, int end);
int						bytecode_read(t_cw *cw, char *file, int	index,
						int color_nb);
t_process				*process_new(t_process **act, int champ, int pc,
						int color_nb);
int						process_count(t_process *l);
void					board_to_int(t_cw *cw, int *value, int offset);
void					int_to_board(t_cw *cw, int *value, int offset);
void					exec_turn(t_cw *cw, int *turn);
void					live(t_cw *cw, t_process *p);
void					ld(t_cw *cw, t_process *p);
void					st(t_cw *cw, t_process *p);
void					add(t_cw *cw, t_process *p);
void					sub(t_cw *cw, t_process *p);
void					and(t_cw *cw, t_process *p);
void					or(t_cw *cw, t_process *p);
void					xor(t_cw *cw, t_process *p);
void					zjmp(t_cw *cw, t_process *p);
void					sti(t_cw *cw, t_process *p);
void					ldi(t_cw *cw, t_process *p);
void					frk(t_cw *cw, t_process *p);
void					lld(t_cw *cw, t_process *p);
void					lldi(t_cw *cw, t_process *p);
void					lfrk(t_cw *cw, t_process *p);
void					aff(t_cw *cw, t_process *p);
t_ocp					ocp_get(unsigned char ocp);
void					ocp_parse(t_cw *cw, t_process *p, t_ocp ocp,
						int dir_two, int get_index);
int						get_turn(unsigned char c);
int						mod(int a, int b);
int						idx_mod(int a);
void					d(t_cw *cw);
void					dump(t_cw *cw);
void					print_winner(t_cw *cw);
int						error(t_cw *cw, char *s);

#endif
