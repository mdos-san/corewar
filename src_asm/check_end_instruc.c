/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end_instruc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 12:57:59 by jcao              #+#    #+#             */
/*   Updated: 2017/02/11 16:53:43 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_asm.h"

int		check_end_instruc(t_asm *var)
{
	while (var->stock[var->i] != '\n' && var->stock[var->i] != '\0')
	{
		if (ft_isspace(var->stock[var->i]) != 1)
		{
			if (var->stock[var->i] == COMMENT_CHAR || var->stock[var->i] == ';')
			{
				while (var->stock[var->i] != '\n' && var->stock[var->i] != '\0')
					var->i++;
				return (1);
			}
			else
				return (-1);
		}
		var->i++;
	}
	return (1);
}
