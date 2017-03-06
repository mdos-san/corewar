/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 11:33:25 by jcao              #+#    #+#             */
/*   Updated: 2017/03/02 16:52:22 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_asm.h"

static t_asm	*count_rl(char c, t_asm *var)
{
	if (c == '\n')
	{
		var->l = 1;
		var->r++;
	}
	else
	{
		if (var->name == 1 && var->comment == 0)
			var->iname++;
		else if (var->comment == 1 && var->name == 0)
			var->icomment++;
		else if (var->name == 1 && var->comment == 1 && var->iname != 0)
			var->icomment++;
		else if (var->name == 1 && var->comment == 1 && var->icomment != 0)
			var->iname++;
		var->l++;
	}
	return (var);
}

static t_asm	*double_check(t_asm *var)
{
	if (var->stock[var->i] == '"')
	{
		var->l++;
		var->i++;
		while (var->stock[var->i] != '"' && var->stock[var->i] != '\0')
		{
			var = count_rl(var->stock[var->i], var);
			var->i++;
		}
		if (var->stock[var->i] != '"')
			return (NULL);
		var->l++;
		var->i++;
	}
	return (var);
}

static int		escape_space2(t_asm *var, int i)
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
			return (i);
		}
		else
			var->l++;
		i++;
	}
	return (i);
}

static int		second_check(t_asm *var)
{
	if (var->stock[var->i] != '\n')
		return (-1);
	else
		var->i++;
	var->r++;
	var->l = 1;
	var->k = var->i;
	var->ll = var->l;
	if ((check_name_str(var)) == 1)
	{
		if ((var->comment != 0 && var->name != 1) || (var->comment != 1 &&
	var->name != 0))
		{
			var->i = var->k;
			var->l = var->ll;
			return (-1);
		}
		var->i = escape_space2(var, var->i);
		if (var->stock[var->i] == '\n')
			return (-1);
		var = double_check(var);
		if (var == NULL)
			return (-1);
	}
	return (1);
}

int				syntax_error(t_asm *var)
{
	var->i = 0;
	var->r = 1;
	var->l = 1;
	var->i = escape_space(var, var->i);
	if ((check_name_str(var)) == 1)
	{
		var->i = escape_space2(var, var->i);
		if (var->stock[var->i] == '\n')
			return (-1);
		var = double_check(var);
		if (var == NULL)
			return (-1);
	}
	else
		return (-1);
	var->k = 0;
	return (second_check(var));
}
