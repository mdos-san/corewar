/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 09:24:53 by ajubert           #+#    #+#             */
/*   Updated: 2016/04/21 09:29:45 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_free(char *str, const char *s1)
{
	char *tmp;

	tmp = str;
	str = ft_strdup(s1);
	free(tmp);
	return (str);
}
