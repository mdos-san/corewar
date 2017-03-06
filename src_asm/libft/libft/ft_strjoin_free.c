/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 09:42:04 by ajubert           #+#    #+#             */
/*   Updated: 2016/04/21 09:45:07 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *str, char const *s1, char const *s2)
{
	char *tmp;

	tmp = str;
	str = ft_strjoin(s1, s2);
	free(tmp);
	return (str);
}
