/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modif_longueur.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 18:27:13 by ajubert           #+#    #+#             */
/*   Updated: 2016/04/07 18:30:37 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_modif_longueur(const char *format, t_env1 *env1, t_env2 *env2)
{
	if (!ft_strchr("hljz", format[env1->taille_f]))
		return ;
	if (ft_strncmp(&format[env1->taille_f], "hh", 2) == 0)
	{
		env2->modif = HH;
		env1->taille_f += 2;
		return ;
	}
	if (ft_strncmp(&format[env1->taille_f], "ll", 2) == 0)
	{
		env2->modif = LL;
		env1->taille_f += 2;
		return ;
	}
	else if (format[env1->taille_f] == 'h')
		env2->modif = H;
	else if (format[env1->taille_f] == 'l')
		env2->modif = L;
	else if (format[env1->taille_f] == 'j')
		env2->modif = J;
	else if (format[env1->taille_f] == 'z')
		env2->modif = Z;
	env1->taille_f++;
}
