/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 14:38:18 by ajubert           #+#    #+#             */
/*   Updated: 2016/01/12 14:38:27 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static int	is_whitespace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	char	*result;

	start = 0;
	result = 0;
	if (!s)
		return (NULL);
	end = ft_strlen(s) - 1;
	while (is_whitespace(s[start]) && s[start] != 0)
		start++;
	if (s[start] == 0)
	{
		result = (char*)malloc(1);
		result[0] = 0;
		return (result);
	}
	while (is_whitespace(s[end]) && end >= 0)
		end--;
	if (end == start)
		return (NULL);
	result = (char*)malloc(end - start + 2);
	result[end - start + 1] = 0;
	ft_strncpy(result, s + start, end - start + 1);
	return (result);
}
