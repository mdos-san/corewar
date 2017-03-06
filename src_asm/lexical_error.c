/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 15:27:08 by jcao              #+#    #+#             */
/*   Updated: 2017/02/10 17:16:08 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_asm.h"

static int	check_quotes(t_asm *var)
{
	if (var->stock[var->i] == '"')
	{
		var->i++;
		while (var->stock[var->i] != '"' && var->stock[var->i] != '\0')
		{
			if (var->stock[var->i] == '\n')
			{
				var->l = 1;
				var->r++;
			}
			var->l++;
			var->i++;
		}
		return (1);
	}
	else
		return (check_name_str(var));
}

static int	check_chars(char c, t_asm *var)
{
	int i;

	i = 0;
	while (LABEL_CHARS[i] != '\0')
	{
		if (c == LABEL_CHARS[i])
		{
			if (var->stock[var->i + 1] == LABEL_CHAR)
			{
				var->l++;
				var->i++;
			}
			return (1);
		}
		else
			i++;
	}
	return (check_quotes(var));
}

static int	check_spe(char c, t_asm *var)
{
	if (c == '-')
		return (1);
	if (ft_isspace(c) == 1)
		return (1);
	if (c == SEPARATOR_CHAR)
		return (1);
	if (c == COMMENT_CHAR || c == ';')
	{
		var->i++;
		while (var->stock[var->i] != '\n' && var->stock[var->i] != '\0')
			var->i++;
		var->l = 1;
		return (1);
	}
	else
		return (check_chars(c, var));
}

static int	check_label(char *stock, t_asm *var)
{
	if (stock[var->i] == DIRECT_CHAR)
	{
		if (ft_isdigit(stock[var->i + 1]) == 1 || stock[var->i + 1] == '-' ||
	stock[var->i + 1] == LABEL_CHAR)
		{
			var->i++;
			var->l++;
			return (1);
		}
	}
	return (check_spe(stock[var->i], var));
}

int			lexical_error(t_asm *var)
{
	var->i = 0;
	while (var->stock[var->i] != '\0')
	{
		if (check_label(var->stock, var) != 1)
			return (-1);
		else
		{
			if (var->stock[var->i] == '\n')
			{
				var->l = 1;
				var->r++;
			}
			else
				var->l++;
			var->i++;
		}
	}
	var->name = 0;
	var->comment = 0;
	return (1);
}
