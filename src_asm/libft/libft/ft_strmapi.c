/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 14:34:29 by ajubert           #+#    #+#             */
/*   Updated: 2016/01/12 14:34:33 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;

	i = 0;
	result = 0;
	if (!s)
		return (NULL);
	result = ft_strdup(s);
	while (*(result + i) != 0)
	{
		*(result + i) = f(i, *(result + i));
		i++;
	}
	return (result);
}
