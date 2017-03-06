/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prog.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 15:40:52 by ajubert           #+#    #+#             */
/*   Updated: 2017/03/02 15:39:17 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_asm.h"

int				test_opcode(char *str)
{
	if (ft_strcmp(str, "live") == 0 || ft_strcmp(str, "zjmp") == 0
			|| ft_strcmp(str, "fork") == 0 || ft_strcmp(str, "lfork") == 0)
		return (0);
	return (1);
}

unsigned char	*foret(t_e *e, t_ijkl *s, int *size_str)
{
	unsigned char *print;

	while (s->l < e->nb_instruct && e->tab[s->l].cmd == 3)
		s->l++;
	if (s->l >= e->nb_instruct)
		return (NULL);
	if (!(print = malloc(sizeof(unsigned char) * e->tab[s->l].nb_octet)))
		exit(0);
	if (!(s->str = ft_strsplit_asm(e->tab[s->l].str, size_str)))
		exit(0);
	if (e->tab[s->l].cmd == 1)
		s->j = 0;
	else
		s->j = 1;
	return (print);
}

void			fin(t_e *e, t_ijkl *s, unsigned char *print, int size_str)
{
	int					k;
	unsigned char		**tmp;

	k = 0;
	while (k < e->tab[s->l].nb_octet)
	{
		ft_printf_fd(e->fd1, "%c", print[k]);
		k++;
	}
	tmp = &print;
	free_line((char **)tmp);
	free_split(&s->str, size_str);
}

void			print_prog(t_e *e)
{
	t_ijkl				s;
	int					size_str;
	int					k;

	s.l = 0;
	while (s.l < e->nb_instruct)
	{
		if (!(s.print = foret(e, &s, &size_str)))
			return ;
		k = 0;
		s.print[k] = search_code(s.str[s.j], e);
		s.i = s.j + 1;
		if (test_opcode(s.str[s.j]))
			s.print[++k] = opcode(s.str, s.i, size_str);
		while (s.i < size_str)
		{
			k++;
			s.print = ft_yo_ne_se_pa(e, &k, s);
			k--;
			s.i++;
		}
		fin(e, &s, s.print, size_str);
		s.l++;
	}
}
