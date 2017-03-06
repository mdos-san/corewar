/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_str_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:27:58 by jcao              #+#    #+#             */
/*   Updated: 2017/02/11 15:25:43 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_asm.h"

static int	escape_error(t_asm *var, int i)
{
	while ((ft_isspace(var->stock[i]) == 1 || var->stock[i] == COMMENT_CHAR ||
	var->stock[i] == ';') && var->stock[i] != '\0')
	{
		if (var->stock[i] == COMMENT_CHAR || var->stock[i] == ';')
		{
			i++;
			while (var->stock[i] != '\n' && var->stock[i] != '\0')
				i++;
		}
		i++;
	}
	return (i);
}

char		*next_str_error(t_asm *var)
{
	int		i;
	int		init;
	char	*tmp;

	i = 0;
	var->i = escape_error(var, var->i);
	init = var->i;
	while (ft_isspace(var->stock[var->i]) != 1 && var->stock[var->i] != '\0')
	{
		var->i++;
		i++;
	}
	var->i = init;
	tmp = ft_strnew(i + 1);
	tmp = ft_strncpy(tmp, &var->stock[var->i], i);
	var->i = var->i + i;
	return (tmp);
}
