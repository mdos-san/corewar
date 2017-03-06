/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 23:53:21 by ajubert           #+#    #+#             */
/*   Updated: 2016/04/28 10:35:16 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_calc_hexa_else(t_env2 *env2)
{
	env2->tmp = ft_unsigned_long_itoa(env2->reste);
	ft_list_push_front(&env2->tmp1, env2->tmp);
	ft_memdel((void **)&env2->tmp);
}

void	ft_calc_hexa(const char *format, t_env1 *env1, t_env2 *env2)
{
	env2->test = 1;
	env2->str = ft_memalloc(2);
	while (env2->argument1 > 0 || env2->test)
	{
		env2->test = 0;
		env2->result = 0;
		env2->reste = env2->argument1 % 16;
		env2->argument1 /= 16;
		if (env2->reste >= 10)
		{
			while (env2->reste != 10 + env2->result)
				env2->result++;
			if (format[env1->taille_f] == 'x')
				env2->c = 'a' + env2->result;
			else
				env2->c = 'A' + env2->result;
			env2->str[0] = env2->c;
			ft_list_push_front(&env2->tmp1, env2->str);
		}
		else
			ft_calc_hexa_else(env2);
	}
	ft_memdel((void **)&env2->str);
}

void	dieze_x_no_moins(t_env2 *env2, char *c)
{
	int i;

	i = 0;
	while (!(ft_isdigit(env2->str[i + 1]) || ft_isalpha(env2->str[i + 1])))
		i++;
	if (env2->str[i] == c[0] && env2->str[i + 1] == c[0])
	{
		env2->str[i] = c[0];
		env2->str[i + 1] = c[1];
	}
	else if (env2->str[i] == ' ' && env2->str[i - 1] == ' ')
	{
		env2->str[i - 1] = c[0];
		env2->str[i] = c[1];
	}
	else
	{
		env2->str[i] = c[1];
		env2->str = ft_strjoin_free(env2->str, "0", env2->str);
	}
}

void	foret_if_hexa(t_env2 *env2, unsigned long res_arg, char *c)
{
	if ((size_t)env2->val_precision > ft_strlen(env2->str))
		ft_precision(env2, ft_strlen(env2->str));
	if (env2->precision == 1 && env2->val_precision == 0 && res_arg == 0)
		env2->str[0] = 0;
	if (env2->taille_min != 0 &&
			(size_t)env2->taille_min > ft_strlen(env2->str))
		ft_taille_min(env2);
	if (env2->dieze && res_arg != 0)
	{
		if (env2->test == 0)
			env2->str = ft_strjoin_free(env2->str, c, env2->str);
		else
		{
			if (!env2->moins)
				dieze_x_no_moins(env2, c);
			else
			{
				env2->str = ft_strjoin(c, env2->str);
				if (env2->test == 1)
					(env2->str[ft_strlen(env2->str) - 2] == ' ') ?
						(env2->str[ft_strlen(env2->str) - 2] = 0) :
						(env2->str[ft_strlen(env2->str) - 1] = 0);
			}
		}
	}
}

void	ft_printf_hexa(const char *format, t_env1 *env1, t_env2 *env2)
{
	unsigned long	res_arg;
	char			*c;
	t_lst			*free_lst;

	c = ft_strdup("0x");
	if (format[env1->taille_f] == 'X')
		c[1] = 'X';
	res_arg = env2->argument1;
	ft_calc_hexa(format, env1, env2);
	env2->str = ft_strdup("\0");
	free_lst = env2->tmp1;
	while (env2->tmp1)
	{
		env2->str = ft_strjoin_free(env2->str, env2->str, env2->tmp1->str);
		env2->tmp1 = env2->tmp1->next;
	}
	ft_free_list(free_lst);
	foret_if_hexa(env2, res_arg, c);
	ft_list_push_back(&env1->list, env2->str);
	ft_memdel((void **)&env2->str);
	ft_memdel((void **)&c);
}
