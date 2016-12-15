/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 19:04:44 by jcao              #+#    #+#             */
/*   Updated: 2015/12/08 16:09:39 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*tmp;
	unsigned int	k;

	k = 0;
	if (!s || !*s)
		return (NULL);
	tmp = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (tmp == NULL)
		return (NULL);
	while (s[k])
	{
		tmp[k] = f(k, s[k]);
		k++;
	}
	tmp[k] = '\0';
	return (tmp);
}
