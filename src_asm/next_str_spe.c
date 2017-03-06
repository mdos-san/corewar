/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_str_spe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 16:17:05 by jcao              #+#    #+#             */
/*   Updated: 2017/02/11 15:26:11 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_asm.h"

static int	check_chars(char c)
{
	int i;

	i = 0;
	while (LABEL_CHARS[i] != '\0')
	{
		if (c == LABEL_CHARS[i])
			return (1);
		else
			i++;
	}
	return (-1);
}

char		*next_str_spe(t_asm *var)
{
	int		i;
	int		init;
	char	*tmp;

	i = 0;
	var->i = escape_space(var, var->i);
	init = var->i;
	while ((check_chars(var->stock[var->i]) == 1 && var->stock[var->i] != '\0')
	|| var->stock[var->i] == ':')
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
