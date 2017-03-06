/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_label_chars.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 15:52:27 by jcao              #+#    #+#             */
/*   Updated: 2017/02/11 16:19:53 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_asm.h"

static int		check_chars(char c)
{
	int i;

	i = 0;
	while (LABEL_CHARS[i] != '\0')
	{
		if (c == LABEL_CHARS[i] || c == LABEL_CHAR)
			return (1);
		else
			i++;
	}
	return (-1);
}

char			*print_label_chars(t_asm *var)
{
	char	*tmp;

	tmp = NULL;
	var->tmp2 = NULL;
	while (check_chars(var->stock[var->i]) == 1)
	{
		if (tmp == NULL)
		{
			tmp = ft_strnew(2);
			tmp[0] = var->stock[var->i];
			tmp[1] = '\0';
		}
		else
		{
			var->tmp2 = ft_strdup(tmp);
			free(tmp);
			tmp = (char *)malloc(sizeof(char) * ft_strlen(var->tmp2) + 2);
			tmp = ft_strcpy(tmp, var->tmp2);
			tmp[ft_strlen(var->tmp2)] = var->stock[var->i];
			tmp[ft_strlen(var->tmp2) + 1] = '\0';
			free(var->tmp2);
		}
		var->i++;
	}
	return (tmp);
}
