/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 15:26:08 by jcao              #+#    #+#             */
/*   Updated: 2017/02/11 15:24:44 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_asm.h"

static int	escape_space2(t_asm *var, int i)
{
	while (ft_isspace(var->stock[i]) == 1 || var->stock[i] == COMMENT_CHAR ||
	var->stock[i] == ';')
	{
		if (var->stock[i] == '\n')
		{
			var->l++;
			return (i);
		}
		else if (var->stock[i] == COMMENT_CHAR || var->stock[i] == ';')
		{
			i++;
			while (var->stock[i] != '\n' && var->stock[i] != '\0')
				i++;
			var->l = 1;
			var->r++;
		}
		var->l++;
		i++;
	}
	return (i);
}

int			next_str(t_asm *var)
{
	int i;

	i = 0;
	var->i = escape_space2(var, var->i);
	if (var->stock[var->i] == '-')
	{
		var->i++;
		var->l++;
	}
	if (var->stock[var->i] == DIRECT_CHAR)
		return (check_dir(var));
	else if (ft_isdigit(var->stock[var->i]) == 1)
		return (check_ind(var));
	else if (var->stock[var->i] == 'r')
		return (check_reg(var));
	else
		return (-1);
	return (1);
}
