/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 09:34:08 by jcao              #+#    #+#             */
/*   Updated: 2015/11/30 11:50:50 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	value;

	i = 0;
	ptr = b;
	value = c;
	while (i < len)
	{
		ptr[i] = value;
		i++;
	}
	return ((void *)b);
}
