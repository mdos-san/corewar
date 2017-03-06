/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_octet.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 12:06:30 by ajubert           #+#    #+#             */
/*   Updated: 2017/03/02 15:38:00 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_asm.h"

int		if_else(char **op, int cmd)
{
	if (ft_strcmp(op[cmd - 1], "zjmp") == 0 ||
			ft_strcmp(op[cmd - 1], "ldi") == 0 ||
			ft_strcmp(op[cmd - 1], "sti") == 0 ||
			ft_strcmp(op[cmd - 1], "fork") == 0 ||
			ft_strcmp(op[cmd - 1], "lldi") == 0 ||
			ft_strcmp(op[cmd - 1], "lfork") == 0)
		return (2);
	else if (ft_strcmp(op[cmd - 1], "live") == 0 ||
			ft_strcmp(op[cmd - 1], "ld") == 0 ||
			ft_strcmp(op[cmd - 1], "and") == 0 ||
			ft_strcmp(op[cmd - 1], "or") == 0 ||
			ft_strcmp(op[cmd - 1], "xor") == 0 ||
			ft_strcmp(op[cmd - 1], "lld") == 0)
		return (4);
	return (0);
}

int		if_else1(char **op, int cmd)
{
	if (ft_strcmp(op[cmd - 1], "live") == 0 ||
			ft_strcmp(op[cmd - 1], "zjmp") == 0 ||
			(ft_strcmp(op[cmd - 1], "fork") == 0) ||
			ft_strcmp(op[cmd - 1], "lfork") == 0)
		return (0);
	else
		return (1);
	return (0);
}

int		foret_if(char **op, int cmd, int i)
{
	int j;

	j = 0;
	if (op[i][j] == ',')
		j++;
	if (op[i][j] == 'r' && ft_isdigit(op[i][j + 1]) &&
			ft_strstr(":", op[i]) == 0)
		return (1);
	if (op[i][j] == DIRECT_CHAR)
		return (if_else(op, cmd));
	if ((op[i][j] == '-' && ft_isdigit(op[i][j + 1])) || ft_isdigit(op[i][j]))
		return (2);
	return (0);
}

int		count_octet(char *str, int cmd)
{
	char	**op;
	int		nb_octet;
	int		i;
	int		size;

	size = 0;
	if (!(op = ft_strsplit_asm((const char *)str, &size)))
		exit(0);
	nb_octet = 1;
	nb_octet += if_else1(op, cmd);
	i = cmd;
	while (i < size)
	{
		nb_octet += foret_if(op, cmd, i);
		i++;
	}
	free_split(&op, size);
	return (nb_octet);
}
