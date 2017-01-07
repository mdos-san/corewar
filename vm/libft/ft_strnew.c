/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 14:47:20 by jcao              #+#    #+#             */
/*   Updated: 2016/04/11 10:05:20 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strnew(size_t size)
{
	char	*tab;
	size_t	i;
	int		k;

	i = 0;
	k = 0;
	tab = (char *)malloc(sizeof(char) * size + 1);
	if (tab == NULL)
		return (NULL);
	while (i < size)
	{
		tab[i] = '\0';
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
