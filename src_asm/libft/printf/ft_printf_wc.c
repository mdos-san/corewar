/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_wc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 06:14:46 by ajubert           #+#    #+#             */
/*   Updated: 2016/04/29 12:41:37 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_wchar(t_env2 *env2, int size)
{
	int i;

	i = 0;
	env2->str = ft_strdup("\0");
	while (i < size)
	{
		ft_printf_wint(env2, env2->wstr[i]);
		i++;
	}
}

int		ft_printf_wc(t_env1 *env1, t_env2 *env2)
{
	env2->wint = va_arg(env1->vl, wint_t);
	if (env2->wint > 1114111)
		return (-1);
	if (env2->wint > 55296 && env2->wint < 57343)
		return (-1);
	env2->wchar = (wchar_t)env2->wint;
	env2->wstr = &env2->wchar;
	if (env2->wint != 0)
		print_wchar(env2, 1);
	else
		ft_printf_ch_null(env1, env2);
	ft_list_push_back(&env1->list, env2->str);
	ft_memdel((void **)&env2->str);
	return (0);
}

void	ft_printf_ws(const char *format, t_env1 *env1, t_env2 *env2)
{
	env2->wstr = va_arg(env1->vl, wchar_t *);
	if (!env2->wstr)
	{
		env2->str = NULL;
		ft_print_string(format, env1, env2);
		return ;
	}
	print_wchar(env2, ft_wstrlen(env2->wstr));
	ft_print_string(format, env1, env2);
}
