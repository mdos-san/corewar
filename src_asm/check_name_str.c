/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:45:58 by jcao              #+#    #+#             */
/*   Updated: 2017/02/11 14:56:47 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_asm.h"

static int		check_com_str(t_asm *var)
{
	int k;
	int len;

	k = 0;
	len = ft_strlen(COMMENT_CMD_STRING);
	while (k < len)
	{
		if (var->stock[var->i] == COMMENT_CMD_STRING[k])
		{
			var->i++;
			var->l++;
			k++;
		}
		else
			return (-1);
	}
	var->l--;
	var->comment++;
	return (1);
}

int				kcount(t_asm *var, int k)
{
	var->i++;
	var->l++;
	k++;
	return (k);
}

int				check_name_str(t_asm *var)
{
	int k;
	int len;
	int initl;

	k = 0;
	var->init = var->i;
	initl = var->l;
	len = ft_strlen(NAME_CMD_STRING);
	while (k < len)
	{
		if (var->stock[var->i] == NAME_CMD_STRING[k])
			k = kcount(var, k);
		else
		{
			var->i = var->init;
			var->l = initl;
			return (check_com_str(var));
		}
	}
	var->l--;
	var->name++;
	return (1);
}
