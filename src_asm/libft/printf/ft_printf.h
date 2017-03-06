/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 16:42:31 by ajubert           #+#    #+#             */
/*   Updated: 2016/04/29 12:33:28 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <wchar.h>

typedef struct		s_lst
{
	char			*str;
	int				size;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_env1
{
	va_list			vl;
	int				nb_param;
	int				taille;
	int				taille_f;
	t_lst			*list;
	t_lst			*tmp;
	char			*str;
	char			*temp;
}					t_env1;

typedef enum		e_modif
{
	NO, HH, H, LL, L, J, Z
}					t_modif;

typedef struct		s_env2
{
	long			argument;
	unsigned long	argument1;
	wint_t			wint;
	int				j;
	char			*str;
	char			c;
	char			*tmp;
	wchar_t			wchar;
	wchar_t			*wstr;
	unsigned long	result;
	void			*quot_p;
	unsigned long	quot_po;
	unsigned long	reste;
	t_lst			*tmp1;
	int				taille_min;
	int				count_space;
	int				precision;
	int				val_precision;
	int				dieze;
	int				plus;
	int				moins;
	int				test;
	int				test1;
	int				zero;
	t_modif			modif;
}					t_env2;

int					ft_printf(const char *format, ...);
void				ft_list_push_back(t_lst **begin_list, char *str);
void				ft_list_push_front(t_lst **begin_list, char *str);
void				ft_flags(const char *format, t_env1 *env1, t_env2 *env2);
void				ft_before_modif_longueur(const char *format, t_env1 *env1,
		t_env2 *env2);
void				ft_printf_ch(t_env1 *env1, t_env2 *env2);
void				ft_print_string(const char *format, t_env1 *env1,
		t_env2 *env2);
void				ft_printf_ent(const char *format, t_env1 *env1,
		t_env2 *env2);
void				ft_printf_octal(t_env1 *env1, t_env2 *env2);
void				ft_printf_hexa(const char *format, t_env1 *env1,
		t_env2 *env2);
int					ft_printf_calc(const char *format, t_env1 *env1,
		t_env2 *env2);
void				ft_printf_p(t_env1 *env1, t_env2 *env2);
int					ft_printf_wc(t_env1 *env1, t_env2 *env2);
void				ft_modif_longueur(const char *format, t_env1 *env1,
		t_env2 *env2);
void				ft_precision(t_env2 *env2, int size_str);
void				ft_taille_min(t_env2 *env2);
void				ft_plus(t_env2 *env2);
void				ft_taille_min_string(t_env2 *env2);
void				ft_printf_wint(t_env2 *env2, wint_t wint);
void				ft_printf_ws(const char *format, t_env1 *env1,
		t_env2 *env2);
void				ft_printf_ch_null(t_env1 *env1, t_env2 *env2);
void				ft_free_list(t_lst *begin_list);

#endif
