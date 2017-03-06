/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 14:19:54 by ajubert           #+#    #+#             */
/*   Updated: 2016/01/12 14:20:43 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#define S1_CAST *(unsigned char*)(s1 + i)
#define S2_CAST *(unsigned char*)(s2 + i)

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (S1_CAST && S2_CAST)
	{
		if (S1_CAST != S2_CAST)
			return ((int)(S1_CAST - S2_CAST));
		i++;
	}
	return ((int)(S1_CAST - S2_CAST));
}
