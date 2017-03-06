/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:41:48 by jcao              #+#    #+#             */
/*   Updated: 2017/02/11 15:18:46 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_asm.h"

static int		only_space(char *str, t_asm *var)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isspace(str[i]) != 1)
		{
			i = ft_strlen(str);
			var->i = var->i - i;
			return (-1);
		}
		i++;
	}
	return (1);
}

static int		next_check2(t_asm *var, char **av)
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
	else if (check_dots(var) == 1)
		return (check_str(var, av));
	else if (only_space(var->instruc, var) == 1)
		return (1);
	else
		return (-1);
	return (-1);
}

int				next_check(t_asm *var, char **av)
{
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
		return (next_check2(var, av));
}
