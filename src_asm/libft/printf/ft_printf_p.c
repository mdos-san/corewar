/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 00:56:09 by ajubert           #+#    #+#             */
/*   Updated: 2016/04/28 10:51:54 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_p_calc(t_env2 *env2)
{
	char *tamp;

	while (env2->quot_po > 0 || env2->test)
	{
		env2->test = 0;
		env2->result = 0;
		env2->reste = env2->quot_po % 16;
		env2->quot_po = env2->quot_po / 16;
		if (env2->reste >= 10)
		{
			while (env2->reste != 10 + env2->result)
				env2->result++;
			env2->c = 'a' + env2->result;
			env2->str[0] = env2->c;
			ft_list_push_front(&env2->tmp1, env2->str);
		}
		else
		{
			tamp = ft_itoa(env2->reste);
			ft_list_push_front(&env2->tmp1, tamp);
			ft_memdel((void **)&tamp);
		}
	}
}

void	dieze_p(t_env2 *env2)
{
	int i;

	i = 0;
	while (!(ft_isdigit(env2->str[i + 1]) || ft_isalpha(env2->str[i + 1])))
		i++;
	if (env2->str[i] == '0' && env2->str[i + 1] == '0')
	{
		env2->str[i] = '0';
		env2->str[i + 1] = 'x';
	}
	else if (env2->str[i] == ' ' && env2->str[i - 1] == ' ')
	{
		env2->str[i - 1] = '0';
		env2->str[i] = 'x';
	}
	else
	{
		env2->str[i] = 'x';
		env2->str = ft_strjoin_free(env2->str, "0", env2->str);
	}
}

void	foret_if_p(t_env2 *env2)
{
	if ((size_t)env2->val_precision > ft_strlen(env2->str))
		ft_precision(env2, ft_strlen(env2->str));
	if (env2->precision == 1 && env2->val_precision == 0 &&
			(unsigned long)env2->quot_p == 0)
		env2->str[0] = 0;
	if (env2->taille_min != 0 &&
			(size_t)env2->taille_min > ft_strlen(env2->str))
		ft_taille_min(env2);
	if (env2->test == 0)
		env2->str = ft_strjoin_free(env2->str, "0x", env2->str);
	else
	{
		if (!env2->moins)
			dieze_p(env2);
		else
		{
			env2->str = ft_strjoin_free(env2->str, "0x", env2->str);
			if (env2->test == 1)
				(env2->str[ft_strlen(env2->str) - 2] == ' ') ?
					(env2->str[ft_strlen(env2->str) - 2] = 0) :
					(env2->str[ft_strlen(env2->str) - 1] = 0);
		}
	}
}

void	ft_printf_p(t_env1 *env1, t_env2 *env2)
{
	t_lst *free_list;

	env2->tmp1 = NULL;
	env2->quot_p = va_arg(env1->vl, void *);
	env2->quot_po = (unsigned long)env2->quot_p;
	env2->test = 1;
	env2->str = ft_memalloc(2);
	ft_printf_p_calc(env2);
	ft_memdel((void **)&env2->str);
	env2->str = ft_strdup("\0");
	free_list = env2->tmp1;
	while (env2->tmp1)
	{
		env2->str = ft_strjoin_free(env2->str, env2->str, env2->tmp1->str);
		env2->tmp1 = env2->tmp1->next;
	}
	ft_free_list(free_list);
	foret_if_p(env2);
	ft_list_push_back(&env1->list, env2->str);
	ft_memdel((void **)&env2->str);
}
