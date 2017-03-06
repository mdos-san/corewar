/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dots.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 12:33:06 by jcao              #+#    #+#             */
/*   Updated: 2017/02/11 14:52:01 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_asm.h"

static int		check_chars(char c)
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

static int		seek_last_char(t_asm *var, char *str)
{
	var->init = 0;
	while (str[var->init] != '\0' && check_chars(str[var->init]) == 1)
		var->init++;
	return (var->init);
}

int				check_dots(t_asm *var)
{
	int i;

	i = seek_last_char(var, var->instruc);
	if (var->stock[var->i - 1] == LABEL_CHAR)
	{
		var->l = var->l + var->init;
		return (1);
	}
	else
		return (-1);
}
