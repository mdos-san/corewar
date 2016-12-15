/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   except_minus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 14:08:32 by jcao              #+#    #+#             */
/*   Updated: 2016/04/08 14:40:57 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*except_minus(char *res)
{
	int		i;
	char	*tmp;
	int		len;

	i = 0;
	while (res[i] != ' ')
		i++;
	len = ft_strlen(res) - 1;
	if (res[i] == ' ')
	{
		tmp = ft_strsub(res, 0, len);
		free(res);
		res = ft_strdup(tmp);
		free(tmp);
	}
	tmp = ft_strjoin("+", res);
	free(res);
	res = ft_strdup(tmp);
	free(tmp);
	return (res);
}
