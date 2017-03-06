/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 16:23:15 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/25 14:31:50 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		count_param(const char *format)
{
	int i;
	int result;

	result = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			while (ft_isdigit(format[i]) || format[i] == ' ')
				i++;
		}
		if (format[i] == '%')
			i++;
		else if (ft_strchr("diDuUoOcxXspCS", format[i]))
			result++;
		i++;
	}
	return (result);
}

static t_lst	*pre_calc(const char *format, t_env1 *env1)
{
	t_env2	env2;

	ft_bzero(&env2, sizeof(t_env2));
	env2.j = env1->taille_f;
	while (format[env1->taille_f] && format[env1->taille_f] != '%')
		env1->taille_f += 1;
	env2.str = ft_memalloc(env1->taille_f + 1);
	env2.str = ft_memcpy(env2.str, &format[env2.j], env1->taille_f - env2.j);
	ft_list_push_back(&env1->list, env2.str);
	free(env2.str);
	env2.str = NULL;
	if (format[env1->taille_f] == '%')
		if (ft_printf_calc(format, env1, &env2) == -1)
		{
			ft_free_list(env1->list);
			return (NULL);
		}
	return (env1->list);
}

static int		ft_printf_under(const char *format, t_env1 *env)
{
	while (env->nb_param > 0)
	{
		if (!(env->list = pre_calc(format, env)))
			return (-1);
		if (format[env->taille_f] != '%')
			env->nb_param--;
		if (format[env->taille_f] != '\0')
			env->taille_f++;
	}
	while (format[env->taille_f] != '\0')
	{
		if (!(env->list = pre_calc(format, env)))
			return (-1);
		if (format[env->taille_f] == '%')
			env->taille_f++;
	}
	return (0);
}

int				ft_printf_fd(int fd, const char *format, ...)
{
	t_env1	env;

	ft_bzero(&env, sizeof(t_env1));
	va_start(env.vl, format);
	env.nb_param = count_param(format);
	if (ft_printf_under(format, &env) == -1)
		return (-1);
	env.tmp = env.list;
	env.str = ft_strdup("\0");
	while (env.tmp)
	{
		env.temp = env.str;
		env.str = ft_strjoin_size(env.temp, env.tmp->str, env.taille,
				env.tmp->size);
		free(env.temp);
		env.taille += env.tmp->size;
		env.tmp = env.tmp->next;
	}
	ft_putstr_size_fd(fd, env.str, env.taille);
	ft_memdel((void **)&env.str);
	va_end(env.vl);
	ft_free_list(env.list);
	return (env.taille);
}
