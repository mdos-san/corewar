/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 12:42:24 by jcao              #+#    #+#             */
/*   Updated: 2015/12/02 13:46:44 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*tmp;

	tmp = (void *)malloc(sizeof(tmp) * size);
	if (tmp == NULL)
		return (NULL);
	if (tmp != '\0')
	{
		ft_bzero(tmp, size);
	}
	return (tmp);
}
