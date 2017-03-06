/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 23:06:13 by ajubert           #+#    #+#             */
/*   Updated: 2016/04/29 12:42:27 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_taille_min_no_moins(t_env2 *env2)
{
	char p;

	p = ' ';
	if (env2->zero)
		p = '0';
	env2->str = ft_memalloc(env2->taille_min + 1);
	if (env2->moins)
	{
		env2->str[0] = '\0';
		env2->j++;
		while (env2->j < env2->taille_min)
		{
			env2->str[env2->j] = p;
			env2->j++;
		}
	}
	else
	{
		env2->str[env2->taille_min - 1] = '\0';
		while (env2->j < env2->taille_min - 1)
		{
			env2->str[env2->j] = p;
			env2->j++;
		}
	}
}

void	ft_printf_ch_null(t_env1 *env1, t_env2 *env2)
{
	if (env2->taille_min > 1)
		ft_taille_min_no_moins(env2);
	else
	{
		env2->str = ft_memalloc(2);
		env2->str[0] = 0;
	}
	ft_list_push_back(&env1->list, env2->str);
	env2->tmp1 = env1->list;
	while (env2->tmp1->next != NULL)
		env2->tmp1 = env2->tmp1->next;
	env2->tmp1->size = 1 + ft_strlen(env2->str);
}

void	ft_printf_ch(t_env1 *env1, t_env2 *env2)
{
	env2->j = 0;
	env2->c = va_arg(env1->vl, int);
	if (!env2->c)
		ft_printf_ch_null(env1, env2);
	else
	{
		env2->str = ft_memalloc(2);
		env2->str[0] = env2->c;
		if ((size_t)env2->taille_min > ft_strlen(env2->str))
			ft_taille_min_string(env2);
		ft_list_push_back(&env1->list, env2->str);
	}
	ft_memdel((void **)&env2->str);
}
