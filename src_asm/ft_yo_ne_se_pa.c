/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_yo_ne_se_pa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:41:22 by ajubert           #+#    #+#             */
/*   Updated: 2017/03/02 15:39:29 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_asm.h"

unsigned char	*ft_dir(t_ijkl s, t_e *e, int *k, int l)
{
	int		nb;
	char	*nb_c;
	int		m;

	nb = 0;
	if (s.str[s.i][l] == '-' || ft_isdigit(s.str[s.i][l]))
		nb = ft_atoi(&s.str[s.i][l]);
	else if (ft_isalpha(s.str[s.i][l + 1]))
		nb = ft_count_to(e, s.l, s.str[s.i]);
	m = 0;
	if (!(nb_c = convert((unsigned int)nb, s.z.dir_sepa)))
		exit(0);
	while (m < s.z.dir_sepa)
	{
		s.print[*k] = nb_c[m];
		m++;
		k[0]++;
	}
	free_line(&nb_c);
	return (s.print);
}

unsigned char	*ft_ind(t_ijkl s, int l, int *k, unsigned char *print)
{
	int		nb;
	char	*nb_c;
	int		m;

	nb = ft_atoi(&s.str[s.i][l]);
	if (!(nb_c = convert((unsigned int)nb, s.z.ind_sepa)))
		exit(0);
	m = 0;
	while (m < s.z.ind_sepa)
	{
		print[*k] = nb_c[m];
		m++;
		k[0]++;
	}
	free_line(&nb_c);
	return (print);
}

unsigned char	*ft_reg(t_ijkl s, int l, unsigned char *print, int *k)
{
	int		nb;
	char	*nb_c;

	nb = ft_atoi(&s.str[s.i][l + 1]);
	if (!(nb_c = convert((unsigned int)nb, 1)))
		exit(0);
	print[*k] = nb_c[0];
	k[0]++;
	free_line(&nb_c);
	return (print);
}

unsigned char	*ft_yo_ne_se_pa(t_e *e, int *k, t_ijkl s)
{
	int			l;

	l = 0;
	if (ft_strcmp(s.str[s.j], "live") == 0 || ft_strcmp(s.str[s.j], "ld") == 0
			|| ft_strcmp(s.str[s.j], "and") == 0
			|| ft_strcmp(s.str[s.j], "or") == 0
			|| ft_strcmp(s.str[s.j], "xor") == 0
			|| ft_strcmp(s.str[s.j], "lld") == 0)
		s.z.dir_sepa = 4;
	else
		s.z.dir_sepa = 2;
	s.z.ind_sepa = 2;
	if (s.str[s.i][l] == ',')
		l++;
	if (s.str[s.i][l] == '%')
	{
		l++;
		s.print = ft_dir(s, e, k, l);
	}
	else if (s.str[s.i][l] == '-' || ft_isdigit(s.str[s.i][l]))
		s.print = ft_ind(s, l, k, s.print);
	else if (s.str[s.i][l] == 'r')
		s.print = ft_reg(s, l, s.print, k);
	return (s.print);
}
