/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fucking_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:47:21 by jcao              #+#    #+#             */
/*   Updated: 2016/04/11 10:40:22 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*space_zero(char *res)
{
	int i;

	i = 0;
	while (res[i] != '\0')
	{
		if (res[i] == ' ')
			res[i] = '0';
		i++;
	}
	if (ft_strchr(res, '-') != NULL)
	{
		i = 0;
		while (res[i] != '-')
			i++;
		res[i] = '0';
		res[0] = '-';
	}
	return (res);
}

static char	*plus_flag(char *res, t_pri var, char *str)
{
	int i;

	i = 0;
	while (res[i] == ' ')
		i++;
	i--;
	var.i = test_len(res, str);
	if (ft_strchr(str, '0') != NULL && var.i == 1 &&
		ft_strchr(str, '.') == NULL)
	{
		res[i] = '0';
		res[0] = '+';
	}
	else if (res[i] == ' ' && i != -1)
		res[i] = '+';
	else if (ft_strchr(str, '-') != NULL)
		res = except_minus(res);
	else
	{
		var.tmp = ft_strjoin("+", res);
		free(res);
		res = ft_strdup(var.tmp);
		free(var.tmp);
	}
	return (res);
}

static char	*hashtag(char *res, char *str, t_pri var)
{
	int i;

	i = 0;
	if ((ft_strchr(str, 'o') != NULL || ft_strchr(str, 'O') != NULL)
	&& ft_atoi(res) != 0)
	{
		if (ft_strchr(str, '.') != NULL && ft_strchr(res, '0') != NULL)
			return (res);
		res = hashtag_o(res, str, var);
	}
	else if (ft_strchr(str, 'x') != NULL && ft_atoi(res) != 0)
		res = hashtag_x(res, str, var);
	else if (ft_strchr(str, 'X') != NULL && ft_atoi(res) != 0)
	{
		var.tmp = ft_strjoin("0X", res);
		free(res);
		res = ft_strdup(var.tmp);
		free(var.tmp);
	}
	return (res);
}

static char	*spacing(char *res, char *str)
{
	char *tmp;

	if (ft_strchr(str, '0') != NULL)
		res[0] = ' ';
	else
	{
		tmp = ft_strjoin(" ", res);
		free(res);
		res = ft_strdup(tmp);
		free(tmp);
	}
	return (res);
}

char		*fucking_flag(char *sub, char *res, t_pri var, char *str)
{
	if (ft_strchr(sub, '+') != NULL && ft_strchr(str, 'u') == NULL &&
	ft_strchr(str, 'p') == NULL && ft_strchr(res, '-') == NULL &&
	ft_strchr(str, 'o') == NULL && ft_strchr(str, 'O') == NULL &&
	ft_strchr(str, 's') == NULL && ft_strchr(str, 'x') == NULL &&
	ft_strchr(str, 'X') == NULL)
		res = plus_flag(res, var, str);
	if (ft_strchr(sub, '0') != NULL && ((ft_strchr(sub, '-') == NULL &&
ft_strchr(str, '.') == NULL) || ft_strchr(str, 's') != NULL ||
ft_strchr(str, 'S') != NULL))
		res = space_zero(res);
	if (ft_strchr(sub, ' ') != NULL && ft_strchr(sub, '+') == NULL &&
ft_strchr(res, '-') == NULL && ft_strchr(str, 'u') == NULL &&
ft_strchr(str, 'p') == NULL && ft_strchr(str, 's') == NULL &&
ft_strchr(str, 'S') == NULL && ft_strchr(str, 'o') == NULL &&
ft_strchr(str, 'x') == NULL && ft_strchr(str, 'O') == NULL &&
ft_strchr(str, 'X') == NULL)
		res = spacing(res, str);
	if (ft_strchr(sub, '#') != NULL)
		res = hashtag(res, str, var);
	return (res);
}
