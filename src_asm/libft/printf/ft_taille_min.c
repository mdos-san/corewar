/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_taille_min.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 20:35:10 by ajubert           #+#    #+#             */
/*   Updated: 2016/04/21 05:58:37 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_taille_min_next(t_env2 *env2, char c, int i)
{
	char *tamp;
	char *free_tmp;

	free_tmp = env2->tmp;
	if (env2->zero && !(env2->precision))
		c = '0';
	tamp = ft_memalloc(env2->taille_min - ft_strlen(env2->str) + 1);
	env2->tmp = ft_strjoin(ft_memset(tamp,
				c, env2->taille_min - ft_strlen(env2->str)), env2->str);
	ft_memdel((void **)&tamp);
	ft_memdel((void **)&free_tmp);
	if (env2->argument < 0 && c == '0')
	{
		i = 0;
		while (env2->tmp[i] != '-')
			i++;
		ft_swap_char(&env2->tmp[0], &env2->tmp[i]);
	}
}

void	ft_taille_min(t_env2 *env2)
{
	int		i;
	char	c;
	char	*tamp;
	char	*free_tmp;

	i = 0;
	c = ' ';
	env2->test = 1;
	env2->tmp = ft_memalloc(env2->taille_min);
	if (!env2->moins)
		ft_taille_min_next(env2, c, i);
	else
	{
		free_tmp = env2->tmp;
		tamp = ft_memalloc(env2->taille_min - ft_strlen(env2->str) + 1);
		env2->tmp = ft_strjoin(env2->str, ft_memset(tamp,
					c, env2->taille_min - ft_strlen(env2->str)));
		ft_memdel((void **)&tamp);
		ft_memdel((void **)&free_tmp);
	}
	free(env2->str);
	env2->str = ft_strdup(env2->tmp);
	ft_memdel((void **)&env2->tmp);
}
