/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:20:27 by jcao              #+#    #+#             */
/*   Updated: 2016/04/11 10:04:35 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;

	cpy = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (cpy == NULL)
		return (NULL);
	ft_strcpy(cpy, s1);
	return (cpy);
}
