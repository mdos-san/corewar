/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:25:33 by jcao              #+#    #+#             */
/*   Updated: 2015/11/27 10:34:53 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (c >= 65 && c <= 90)
		return ((unsigned char)1);
	else if (c >= 97 && c <= 122)
		return ((unsigned char)1);
	else if (c >= 48 && c <= 57)
		return ((unsigned char)1);
	else
		return ((unsigned char)0);
}
