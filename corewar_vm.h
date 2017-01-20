/* *****	********************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vm.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 13:38:55 by jcao              #+#    #+#             */
/*   Updated: 2016/12/03 13:36:20 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include "op.h"
# define DEBUG 1
# define NB_COL	64

#define SIZE_MAP MEM_SIZE * 4

typedef struct 		s_op
{
	int 		nb_arg;
	char 		*instruct;
	char		*typ_arg; // hard cast 
	int 		nb_instruct;
	int 		nb_tour;
	char 		*descrip;
	int 		bin_octet; // is_octet de codage
	int 		label_size; // label size(4-2 / 0-1)
}					t_op;

typedef struct		s_war
{
	int 			fd;
	int 			nb_champ;
	header_t		*head_lnk;
	char 			**list_champ;
	void			(*fct_tab[17])(struct s_war*, t_champ*);
	int 			last_live; // nb du dernier champion
	int 			current_cycle;
	int 			total_cycle;
	t_op			*set; // set de donnée
	t_process		*proc;
	char			map[MEM_SIZE * 4]; // get map d'int pour faire des binaires d'activations (surlignage, last champion ) + //MALLOC ?
	int 			CYCLE_TO_DIE;
	int 			total_live;

	int 			check;
	int 			current_lives;
	int 			nb_process;
	t_process		*last_chain;
}					t_war;

typedef struct 		s_process
{
	int  		PC;//char		*PC; //typage osef
	int 		pc_tmp;
	char 		carry;
	int 		num_champ; // champion associe
	int 		live;
	int			is_waiting;
	int			waiting_turn;
	unsigned int 	data[3];
	char		reg[REG_SIZE * REG_NUMBER]; //MALLOC ?
	int 		decal_arg;
	struct 		s_process *next;
}				t_process;

void			check_exec(t_war *check, char *str);
void			error_magic(char *fil);
void			get_name(t_war *var, header_t *head, int elem);
void			size_prog(t_war *var, header_t *head, int elem);
void			get_comment(t_war *var, header_t *head, int elem);
void			get_prog(t_war *var, header_t *head, int elem);
void			set_champ(t_war *var, header_t *head);
void			cpy_int_string(int *ptr, int *string);
int				intro_display(t_war *var, header_t *head);
#endif
