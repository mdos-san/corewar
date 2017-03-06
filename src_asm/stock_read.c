/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 16:00:51 by jcao              #+#    #+#             */
/*   Updated: 2017/02/11 16:03:03 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_asm.h"

static char		*stock_read2(t_asm *var, char *res)
{
	char *tmp;
	char *tmp2;

	tmp = ft_strdup(res);
	free(res);
	tmp2 = ft_strnew(1);
	tmp2[0] = var->buf;
	res = ft_strjoin(tmp, tmp2);
	free(tmp);
	free(tmp2);
	return (res);
}

char			*stock_read(t_asm *var)
{
	char	*res;
	int		i;

	res = NULL;
	while (read(var->fd, &var->buf, 1) > 0 && var->buf != '\0')
	{
		if (res == NULL)
		{
			res = ft_strdup(&var->buf);
			res[1] = '\0';
		}
		else
			res = stock_read2(var, res);
	}
	if (res != NULL)
	{
		i = ft_strlen(res);
		res[i] = '\0';
	}
	return (res);
}
