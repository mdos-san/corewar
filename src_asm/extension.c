/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 14:29:19 by jcao              #+#    #+#             */
/*   Updated: 2017/02/11 16:36:40 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_asm.h"

static char	*fill_str(char *res, int i, int len, char *str)
{
	res = ft_strnew(len);
	res = ft_strcpy(res, str);
	res[i] = '.';
	res[i + 1] = 'c';
	res[i + 2] = 'o';
	res[i + 3] = 'r';
	res[i + 4] = '\0';
	return (res);
}

char		*extension(char *str)
{
	char	*res;
	int		i;
	int		len;

	res = NULL;
	i = 0;
	if (str == NULL)
		return (ft_strdup(".cor"));
	else
	{
		while (str[i] != '\0')
			i++;
		len = i + 4;
		while (i > 0)
		{
			if (str[i] == '.')
				return (fill_str(res, i, len, str));
			i--;
		}
		res = ft_strdup(".cor");
	}
	return (res);
}
