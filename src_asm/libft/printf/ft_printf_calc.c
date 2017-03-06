/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_calc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 00:34:12 by ajubert           #+#    #+#             */
/*   Updated: 2016/04/28 10:20:17 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	signed_conv(const char *format, t_env1 *env1, t_env2 *env2)
{
	if (env2->modif == L || format[env1->taille_f] == 'D')
		env2->argument = va_arg(env1->vl, long);
	else if (env2->modif == HH)
		env2->argument = (char)va_arg(env1->vl, int);
	else if (env2->modif == H)
		env2->argument = (short)va_arg(env1->vl, int);
	else if (env2->modif == LL)
		env2->argument = va_arg(env1->vl, long long);
	else if (env2->modif == J)
		env2->argument = va_arg(env1->vl, long);
	else if (env2->modif == Z)
		env2->argument = va_arg(env1->vl, ssize_t);
	else
		env2->argument = va_arg(env1->vl, int);
}

void	unsigned_conv(const char *format, t_env1 *env1, t_env2 *env2)
{
	if (env2->modif == L || ft_strchr("OU", format[env1->taille_f]))
		env2->argument1 = va_arg(env1->vl, unsigned long);
	else if (env2->modif == HH)
		env2->argument1 = (unsigned char)va_arg(env1->vl, unsigned int);
	else if (env2->modif == H)
		env2->argument1 = (unsigned short)va_arg(env1->vl, unsigned int);
	else if (env2->modif == LL)
		env2->argument1 = va_arg(env1->vl, unsigned long long);
	else if (env2->modif == J)
		env2->argument1 = va_arg(env1->vl, unsigned long);
	else if (env2->modif == Z)
		env2->argument1 = va_arg(env1->vl, size_t);
	else
		env2->argument1 = va_arg(env1->vl, unsigned int);
}

void	printf_num(const char *format, t_env1 *env1, t_env2 *env2)
{
	if (ft_strchr("diD", format[env1->taille_f]))
		signed_conv(format, env1, env2);
	else
		unsigned_conv(format, env1, env2);
	if (ft_strchr("diDuU", format[env1->taille_f]))
		ft_printf_ent(format, env1, env2);
	else if (ft_strchr("oO", format[env1->taille_f]))
		ft_printf_octal(env1, env2);
	else if (ft_strchr("xX", format[env1->taille_f]))
		ft_printf_hexa(format, env1, env2);
}

int		printf_str(const char *format, t_env1 *env1, t_env2 *env2)
{
	if (env2->modif == L || ft_strchr("CS", format[env1->taille_f]))
	{
		if (ft_strchr("cC", format[env1->taille_f]))
		{
			if (ft_printf_wc(env1, env2) == -1)
				return (-1);
		}
		else if (ft_strchr("sS", format[env1->taille_f]))
			ft_printf_ws(format, env1, env2);
	}
	else
	{
		if (format[env1->taille_f] == 'c')
			ft_printf_ch(env1, env2);
		else if (format[env1->taille_f] == 's')
		{
			env2->str = ft_strdup(va_arg(env1->vl, char *));
			ft_print_string(format, env1, env2);
		}
	}
	return (0);
}

int		ft_printf_calc(const char *format, t_env1 *env1, t_env2 *env2)
{
	env1->taille_f += 1;
	ft_before_modif_longueur(format, env1, env2);
	ft_modif_longueur(format, env1, env2);
	if (format[env1->taille_f] == '%')
	{
		env2->str = ft_strdup("%");
		ft_print_string(format, env1, env2);
	}
	else if (ft_strchr("idDoOuUxX", format[env1->taille_f]))
		printf_num(format, env1, env2);
	else if (format[env1->taille_f] == 'p')
		ft_printf_p(env1, env2);
	else if (ft_strchr("csCS", format[env1->taille_f]))
	{
		if (printf_str(format, env1, env2) == -1)
			return (-1);
	}
	else
		return (-1);
	return (0);
}
