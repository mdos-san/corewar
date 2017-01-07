/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 12:43:28 by jcao              #+#    #+#             */
/*   Updated: 2015/12/21 15:28:33 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_split(char **resu, char const *str, char c1, size_t i2)
{
	size_t	start;
	size_t	end;
	size_t	index;

	start = 0;
	end = 0;
	index = 0;
	while (str[i2] != '\0')
	{
		while (str[i2] == c1 && str[i2])
			i2++;
		start = i2;
		while (str[i2] != c1 && str[i2])
			i2++;
		end = i2;
		if (end > start)
		{
			resu[index] = ft_strsub(str, start, end - start);
			index++;
		}
	}
	resu[index] = NULL;
	return (resu);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	index;

	res = 0;
	i = 0;
	index = 0;
	res = (char **)malloc(sizeof(char *) * ft_strlen(s) + 1);
	if (res == NULL)
		return (NULL);
	res = ft_split(res, s, c, i);
	return (res);
}
