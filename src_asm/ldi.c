/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 12:46:39 by jcao              #+#    #+#             */
/*   Updated: 2017/03/06 15:58:23 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_asm.h"

static char		*take_line(t_asm *var)
{
	int		i;
	int		init;
	char	*tmp;

	i = 0;
	init = var->i;
	while (var->stock[var->i] != '\n' && var->stock[var->i] != '\0')
	{
		var->i++;
		i++;
	}
	var->i = init;
	tmp = ft_strnew(i + 1);
	if (tmp == NULL)
		exit(0);
	tmp = ft_strncpy(tmp, &var->stock[var->i], i);
	tmp[i] = '\0';
	return (tmp);
}

static int		nb_param(char *str)
{
	int i;
	int len;

	i = 0;
	len = 1;
	while (str[i] != '\n' && str[i] != '\0')
	{
		if (str[i] == SEPARATOR_CHAR)
			len++;
		i++;
	}
	return (len);
}

static int		ldi2(t_asm *var, int res)
{
	if (res != 3 && res != 1 && res != 2)
		return (error_type(var, 1, res));
	res = check_sep(var);
	if (res != 1)
		return (-1);
	res = next_str(var);
	if (res != 3 && res != 1)
		return (error_type(var, 2, res));
	res = check_sep(var);
	if (res != 1)
		return (-1);
	res = next_str(var);
	if (res != 3)
		return (error_type(var, 2, res));
	res = check_end_instruc(var);
	if (res != 1)
		return (-1);
	return (res);
}

int				ldi(t_asm *var)
{
	int len;
	int res;

	var->l = var->l + 3;
	var->tmp = take_line(var);
	len = nb_param(var->tmp);
	if (len != 3)
		return (-4);
	free(var->tmp);
	var->tmp = NULL;
	res = next_str(var);
	res = ldi2(var, res);
	return (res);
}
