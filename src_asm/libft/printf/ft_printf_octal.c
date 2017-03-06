/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_octal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 23:46:40 by ajubert           #+#    #+#             */
/*   Updated: 2016/04/28 11:10:32 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dieze_octal(t_env2 *env2)
{
	int i;

	i = 0;
	if (env2->test == 0 && env2->test1 == 0)
	{
		env2->tmp = env2->str;
		env2->str = ft_strjoin("0", env2->str);
		free(env2->tmp);
	}
	else
	{
		if (!env2->moins)
		{
			while (!(ft_isdigit(env2->str[i + 1])))
				i++;
			env2->str[i] = '0';
		}
		else
		{
			env2->str = ft_strjoin("0", env2->str);
			if (env2->test == 1)
				env2->str[ft_strlen(env2->str) - 1] = 0;
		}
	}
}

void	foret_if_octal(t_env1 *env1, t_env2 *env2, unsigned long res_arg)
{
	if (res_arg == 0)
		env2->str = ft_strdup_free(env2->str, "0");
	if ((size_t)env2->val_precision > ft_strlen(env2->str))
	{
		ft_precision(env2, ft_strlen(env2->str));
		env2->test1 = 1;
	}
	if (env2->precision == 1 && env2->val_precision == 0 && res_arg == 0)
		env2->str[0] = 0;
	if (env2->taille_min != 0 &&
			(size_t)env2->taille_min > ft_strlen(env2->str))
		ft_taille_min(env2);
	if (env2->dieze == 1 && ((res_arg == 0 && env2->precision) || res_arg != 0))
		dieze_octal(env2);
	ft_list_push_back(&env1->list, env2->str);
	ft_memdel((void **)&env2->str);
}

void	ft_printf_octal(t_env1 *env1, t_env2 *env2)
{
	unsigned long	res_arg;
	t_lst			*free_lst;

	env2->result = 0;
	env2->j = 0;
	res_arg = env2->argument1;
	env2->tmp1 = NULL;
	while (env2->argument1 > 0)
	{
		env2->reste = env2->argument1 % 8;
		env2->argument1 /= 8;
		env2->tmp = ft_unsigned_long_itoa(env2->reste);
		ft_list_push_front(&env2->tmp1, env2->tmp);
		ft_memdel((void **)&env2->tmp);
	}
	env2->str = ft_strdup("\0");
	free_lst = env2->tmp1;
	while (env2->tmp1)
	{
		env2->str = ft_strjoin_free(env2->str, env2->str, env2->tmp1->str);
		env2->tmp1 = env2->tmp1->next;
	}
	ft_free_list(free_lst);
	foret_if_octal(env1, env2, res_arg);
}
