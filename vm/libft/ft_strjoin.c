/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 12:17:44 by jcao              #+#    #+#             */
/*   Updated: 2016/04/11 10:04:42 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strccat(char *resu, char const *ss2, size_t i2, size_t k2)
{
	while (ss2[k2] != '\0')
	{
		resu[i2] = ss2[k2];
		i2++;
		k2++;
	}
	resu[i2] = '\0';
	return (resu);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	finalsize;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (!s1 || !s2)
		return (NULL);
	finalsize = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (finalsize + 1));
	if (res == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	ft_strccat(res, s2, i, k);
	return (res);
}
