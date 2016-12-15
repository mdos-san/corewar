/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 14:13:07 by jcao              #+#    #+#             */
/*   Updated: 2016/04/11 10:43:27 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*loop_join(char *sub, char *num, int i)
{
	char *tmp;
	char *tmp2;

	while (sub[i + 1] == '1' || sub[i + 1] == '2' || sub[i + 1] == '3' ||
sub[i + 1] == '4' || sub[i + 1] == '5' || sub[i + 1] == '6' || sub[i] ==
'7' || sub[i + 1] == '8' || sub[i + 1] == '9' || sub[i + 1] == '0')
	{
		i++;
		tmp = ft_strnew(2);
		tmp[0] = sub[i];
		tmp2 = ft_strjoin(num, tmp);
		free(num);
		num = ft_strnew(ft_strlen(tmp2));
		num = ft_strcpy(num, tmp2);
		free(tmp);
		free(tmp2);
	}
	return (num);
}

static int	check_flag(char *format, int i)
{
	if (format[i] == '-')
		return (0);
	else if (format[i] == '+')
		return (0);
	else if (format[i] == ' ')
		return (0);
	else if (format[i] == '#')
		return (0);
	else if (format[i] == '0')
		return (0);
	else
		return (1);
	return (1);
}

int			test_len(char *res, char *str)
{
	int		i;
	int		reslen;
	char	*num;
	int		len;

	num = ft_strnew(2);
	i = 0;
	len = 0;
	reslen = ft_strlen(res);
	while (check_flag(str, i) == 0)
		i++;
	if (str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' ||
	str[i] == '5' || str[i] == '6' || str[i] == '7' || str[i] == '8' ||
	str[i] == '9' || str[i] == '0')
	{
		num[0] = str[i];
		num = loop_join(str, num, i);
		len = ft_atoi(num);
	}
	free(num);
	if (reslen > len)
		return (0);
	else
		return (1);
}
