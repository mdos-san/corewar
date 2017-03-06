/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 15:17:50 by jcao              #+#    #+#             */
/*   Updated: 2017/02/10 17:01:52 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_asm.h"

int	escape_space(t_asm *var, int i)
{
	while (ft_isspace(var->stock[i]) == 1 || var->stock[i] == COMMENT_CHAR ||
	var->stock[i] == ';')
	{
		if (var->stock[i] == '\n')
		{
			var->r++;
			var->l = 1;
		}
		else if (var->stock[i] == COMMENT_CHAR || var->stock[i] == ';')
		{
			i++;
			while (var->stock[i] != '\n' && var->stock[i] != '\0')
				i++;
			var->l = 1;
			var->r++;
		}
		else
			var->l++;
		i++;
	}
	return (i);
}
