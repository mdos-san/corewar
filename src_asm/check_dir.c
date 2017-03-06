/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 10:56:53 by jcao              #+#    #+#             */
/*   Updated: 2017/02/11 14:51:45 by jcao             ###   ########.fr       */
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

static int	check_dir2(t_asm *var)
{
	if (var->stock[var->i] == '-')
	{
		var->i++;
		var->l++;
	}
	while (ft_isdigit(var->stock[var->i]) == 1)
	{
		var->i++;
		var->l++;
	}
	return (var->i);
}

static int	bad_list(t_asm *var, char *tmp)
{
	var->l = var->l - 2;
	var->i = var->i - 2;
	if (var->error == NULL)
		var->error = ft_strdup(tmp);
	else
	{
		free(var->error);
		var->error = ft_strdup(tmp);
	}
	return (-3);
}

int			check_dir(t_asm *var)
{
	int		i;
	int		init;
	char	*tmp;

	var->i++;
	var->l++;
	if (var->stock[var->i] == LABEL_CHAR)
	{
		var->i++;
		var->l++;
		init = var->i;
		while (check_chars(var->stock[var->i]) == 1)
			var->i++;
		i = var->i - init;
		tmp = ft_strnew(i + 1);
		var->i = init;
		tmp = ft_strncpy(tmp, &var->stock[var->i], i);
		if (check_list(&var->list, tmp) != 1)
			return (bad_list(var, tmp));
		var->l = var->l + i;
		var->i = var->i + i;
	}
	else
		var->i = check_dir2(var);
	return (1);
}
