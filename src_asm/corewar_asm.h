/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_asm.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:31:07 by jcao              #+#    #+#             */
/*   Updated: 2017/03/06 14:18:56 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_ASM_H
# define COREWAR_ASM_H

# include "libft//libft/libft.h"
# include "op.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# define DIRECT		"direct"
# define INDIRECT	"indirect"
# define REGISTER	"register"
# define NB_OP 16

typedef struct		s_parse
{
	char			*str;
	struct s_parse	*next;
}					t_parse;

typedef struct		s_asm
{
	int		fd;
	int		l;
	int		r;
	int		i;
	int		k;
	int		ll;
	int		check_n;
	int		init;
	int		name;
	int		comment;
	int		type;
	int		type_code;
	int		first;
	int		iname;
	int		icomment;
	char	buf;
	char	*stock;
	char	*tmp;
	char	*tmp2;
	char	**param;
	char	*instruc;
	char	*error;
	char	*final;
	t_parse	*list;
}					t_asm;

typedef struct		s_liste
{
	char				*str;
	struct s_liste		*next;
}					t_liste;

typedef struct		s_op_ft
{
	int					nb_octet;
	int					cmd;
	char				*ft;
	char				*str;
}					t_op_ft;

typedef struct		s_e
{
	char				*line;
	int					fd;
	int					fd1;
	t_liste				*liste;
	char				*str;
	t_header			header;
	int					nb_instruct;
	t_op_ft				*tab;
	char				**liste_op;
	char				*print;
	int					op;
	int					i;
}					t_e;

typedef struct		s_sepa
{
	int					dir_sepa;
	int					ind_sepa;
}					t_sepa;

typedef struct		s_ijkl
{
	int					i;
	int					j;
	int					l;
	char				**str;
	unsigned char		*print;
	t_sepa				z;
}					t_ijkl;

typedef struct		s_jk
{
	int					j;
	int					k;
}					t_jk;

int					check_name(t_asm *var);
char				*stock_read(t_asm *var);
int					lexical_error(t_asm *var);
int					print_lexical(t_asm *var);
int					check_name_str(t_asm *var);
int					syntax_error(t_asm *var);
int					print_syntax(t_asm *var);
t_parse				*create_list(t_asm *var);
int					seek_instruc(t_asm *var, char **av);
int					seek_instruc2(t_asm *var, char **av);
int					escape_space(t_asm *var, int i);
int					check_str(t_asm *var, char **av);
int					first_check(t_asm *var, char **av);
int					check_normal(t_asm *var, char **av);
int					next_check(t_asm *var, char **av);
int					live(t_asm *var);
int					next_str(t_asm *var);
int					define_type(char *str, t_asm *var);
int					check_dir(t_asm *var);
int					check_ind(t_asm *var);
int					check_reg(t_asm *var);
int					check_list(t_parse **list, char *str);
char				*next_str_spe(t_asm *var);
char				*next_str_error(t_asm *var);
char				*extension(char *str);
int					print_errors(int num, t_asm *var);
int					error_type(t_asm *var, int type, int res);
int					check_sep(t_asm *var);
int					ld(t_asm *var);
int					st(t_asm *var);
int					add(t_asm *var);
int					and_instruc(t_asm *var);
int					or_instruc(t_asm *var);
int					ldi(t_asm *var);
int					sti(t_asm *var);
int					lld(t_asm *var);
int					lldi(t_asm *var);
int					lfork(t_asm *var);
int					aff(t_asm *var);
int					check_dots(t_asm *var);
int					check_end_instruc(t_asm *var);
char				*print_label_chars(t_asm *var);
void				free_line(char **line);
int					recup_file(t_e *e);
t_liste				*push_back_l(t_liste *begin_list, char *str);
void				create_header(t_e *e);
int					count_nb_instruct(t_liste *liste, t_e *e);
int					op_or_ft(char *str, t_e *e);
char				*first_word(char *str);
int					count_octet(char *str, int cmd);
void				init_liste_op(t_e *e);
char				**ft_strsplit_asm(char const *s, int *size);
char				*convert(unsigned int n, int size);
unsigned char		search_code(char *str, t_e *e);
void				print_prog(t_e *e);
unsigned char		opcode(char **str, int i, int size_str);
int					ft_count_to(t_e *e, int i, char *str);
void				ft_free_all(t_e *e);
void				free_split(char ***str, int size);
void				free_tab(t_op_ft **tab, int size);
void				ft_free_list_l(t_liste **begin_list);
void				free_liste_op(char ***tab);
int					write_file(int argc, char **argv);
unsigned char		*ft_yo_ne_se_pa(t_e *e, int *k, t_ijkl s);
void				create_tab(t_e *e);
char				*create_headerfin(char *res, int j, t_liste *tmp, int i);

#endif
