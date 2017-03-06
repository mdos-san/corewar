/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_before_modif_longueur.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 22:44:16 by ajubert           #+#    #+#             */
/*   Updated: 2016/04/14 06:43:45 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_before_modif_longueur(const char *format, t_env1 *env1, t_env2 *env2)
{
	if (ft_strchr("#+-0 ", format[env1->taille_f]))
		ft_flags(format, env1, env2);
	if (ft_isdigit(format[env1->taille_f]))
	{
		env2->taille_min = ft_atoi(&format[env1->taille_f]);
		while (ft_isdigit(format[env1->taille_f]))
			env1->taille_f += 1;
	}
	if (ft_strchr("#+-0 ", format[env1->taille_f]))
		ft_flags(format, env1, env2);
	if (format[env1->taille_f] == '.')
	{
		env1->taille_f += 1;
		env2->precision = 1;
		if (ft_isdigit(format[env1->taille_f]))
		{
			env2->val_precision = ft_atoi(&format[env1->taille_f]);
			while (ft_isdigit(format[env1->taille_f]))
				env1->taille_f += 1;
		}
	}
}
