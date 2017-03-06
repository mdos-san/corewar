/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 11:31:50 by jcao              #+#    #+#             */
/*   Updated: 2017/01/26 11:40:58 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_asm.h"

int			check_sep(t_asm *var)
{
	while (ft_isspace(var->stock[var->i]) == 1)
	{
		if (var->stock[var->i] == '\n')
			return (-1);
		var->i++;
		var->l++;
	}
	if (var->stock[var->i] == SEPARATOR_CHAR)
	{
		var->i++;
		var->l++;
		return (1);
	}
	return (-1);
}
