/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 23:21:27 by ajubert           #+#    #+#             */
/*   Updated: 2016/04/23 22:52:15 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_taille_min_string(t_env2 *env2)
{
	char p;
	char *free_str;

	p = ' ';
	if (env2->zero)
		p = '0';
	env2->j = 0;
	env2->tmp = ft_memalloc(env2->taille_min - ft_strlen(env2->str) + 1);
	while ((size_t)env2->j < env2->taille_min - ft_strlen(env2->str))
	{
		env2->tmp[env2->j] = p;
		env2->j++;
	}
	free_str = env2->str;
	if (env2->moins)
		env2->str = ft_strjoin(env2->str, env2->tmp);
	else
		env2->str = ft_strjoin(env2->tmp, env2->str);
	ft_memdel((void **)&free_str);
	ft_memdel((void **)&env2->tmp);
}

void	ft_print_string(const char *format, t_env1 *env1, t_env2 *env2)
{
	if (env2->str == NULL)
	{
		env2->test = 1;
		env2->str = ft_strdup("(null)");
	}
	if (env2->precision && (size_t)env2->val_precision < ft_strlen(env2->str)
			&& format[env1->taille_f] != '%')
		ft_bzero(&env2->str[env2->val_precision],
				ft_strlen(&env2->str[env2->val_precision]));
	if ((size_t)env2->taille_min > ft_strlen(env2->str))
		ft_taille_min_string(env2);
	ft_list_push_back(&env1->list, env2->str);
	ft_memdel((void **)&env2->str);
}
