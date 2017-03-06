/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_str2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:46:54 by jcao              #+#    #+#             */
/*   Updated: 2017/02/11 15:11:59 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_asm.h"

static int		escape_space2(t_asm *var, int i)
{
	while (ft_isspace(var->stock[i]) == 1 || var->stock[i] == COMMENT_CHAR ||
	var->stock[i] == ';')
	{
		if (var->stock[i] == '\n')
		{
			var->l = 1;
			return (1);
		}
		else if (var->stock[i] == COMMENT_CHAR || var->stock[i] == ';')
		{
			i++;
			while (var->stock[i] != '\n' && var->stock[i] != '\0')
				i++;
			var->l = 1;
			var->r++;
			return (1);
		}
		i++;
	}
	return (-1);
}

static int		check_str3(t_asm *var)
{
	if (ft_strcmp(var->instruc, "or") == 0)
		return (or_instruc(var));
	else if (ft_strcmp(var->instruc, "ldi") == 0)
		return (ldi(var));
	else if (ft_strcmp(var->instruc, "sti") == 0)
		return (sti(var));
	else if (ft_strcmp(var->instruc, "lld") == 0)
		return (lld(var));
	else if (ft_strcmp(var->instruc, "lldi") == 0)
		return (lldi(var));
	else if (ft_strcmp(var->instruc, "lfork") == 0)
		return (lfork(var));
	else if (ft_strcmp(var->instruc, "aff") == 0)
		return (aff(var));
	else if (var->instruc[0] == '\0')
		return (1);
	else
		return (-1);
	return (1);
}

int				check_str(t_asm *var, char **av)
{
	if (escape_space2(var, var->i) == 1)
		return (seek_instruc(var, av));
	free(var->instruc);
	var->instruc = next_str_spe(var);
	if (ft_strcmp(var->instruc, "live") == 0 ||
	ft_strcmp(var->instruc, "zjmp") == 0 ||
	ft_strcmp(var->instruc, "fork") == 0)
		return (live(var));
	else if (ft_strcmp(var->instruc, "ld") == 0)
		return (ld(var));
	else if (ft_strcmp(var->instruc, "st") == 0)
		return (st(var));
	else if (ft_strcmp(var->instruc, "add") == 0 ||
	ft_strcmp(var->instruc, "sub") == 0)
		return (add(var));
	else if (ft_strcmp(var->instruc, "and") == 0 ||
	ft_strcmp(var->instruc, "xor") == 0)
		return (and_instruc(var));
	else
		return (check_str3(var));
}
