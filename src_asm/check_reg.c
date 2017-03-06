/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_reg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 11:51:13 by jcao              #+#    #+#             */
/*   Updated: 2017/02/11 15:03:10 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_asm.h"

static	char		*str_num(char *str, t_asm *var)
{
	char	*tmp;
	int		i;

	if (str == NULL)
	{
		str = ft_strnew(2);
		str[0] = var->stock[var->i];
		str[1] = '\0';
	}
	else
	{
		i = ft_strlen(str);
		tmp = (char *)malloc(sizeof(char) * i + 2);
		tmp = ft_strcpy(tmp, str);
		tmp[i] = var->stock[var->i];
		tmp[i + 1] = '\0';
		free(str);
		str = ft_strdup(tmp);
		free(tmp);
	}
	return (str);
}

int					len_correct(t_asm *var)
{
	var->i--;
	return (-1);
}

int					check_reg(t_asm *var)
{
	int		init;
	int		len;
	char	*res;
	int		num;

	var->i++;
	var->l++;
	init = var->i;
	res = NULL;
	while (ft_isdigit(var->stock[var->i]) == 1)
	{
		res = str_num(res, var);
		var->i++;
		var->l++;
	}
	len = var->i - init;
	if (len == 0)
		return (len_correct(var));
	num = ft_atoi(res);
	if (num > REG_NUMBER)
		return (-2);
	free(res);
	return (3);
}
