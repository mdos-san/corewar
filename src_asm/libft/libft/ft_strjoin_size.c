/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 23:06:29 by ajubert           #+#    #+#             */
/*   Updated: 2016/04/14 05:44:11 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strjoin_size(char const *s1, char const *s2,
		size_t size1, size_t size2)
{
	int		len;
	char	*result;

	result = 0;
	len = 0;
	if (!s1 || !s2)
		return (NULL);
	len = size1 + size2;
	result = (char*)malloc(len + 1);
	if (result == NULL)
		return (NULL);
	result[len] = 0;
	ft_bzero(result, len);
	ft_strnncpy(result, s1, size1);
	ft_strnncpy(&result[size1], s2, size2);
	return (result);
}
