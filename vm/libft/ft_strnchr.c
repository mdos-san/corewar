/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 14:16:05 by jcao              #+#    #+#             */
/*   Updated: 2016/04/11 10:05:00 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strnchr(const char *s, int c, int i)
{
	char	*ptr;

	ptr = (char *)s;
	while (ptr[i] != (char)c && ptr[i] != '\0')
		i++;
	if (ptr[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}
