/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 11:49:10 by jcao              #+#    #+#             */
/*   Updated: 2016/04/11 10:05:28 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;

	i = 0;
	res = ft_strnew(len);
	if (!s || !*s)
		return (NULL);
	if (res == NULL)
		return (NULL);
	while (s[start] != '\0' && i < len)
	{
		res[i] = s[start];
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
}
