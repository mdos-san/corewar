/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 14:34:15 by ajubert           #+#    #+#             */
/*   Updated: 2016/01/12 14:34:20 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*result;

	i = 0;
	result = 0;
	if (s == 0)
		return (NULL);
	result = ft_strdup(s);
	while (*(result + i) != 0)
	{
		*(result + i) = f(*(result + i));
		i++;
	}
	return (result);
}
