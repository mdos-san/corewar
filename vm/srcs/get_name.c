/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_comment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 11:29:12 by jcao              #+#    #+#             */
/*   Updated: 2016/12/05 11:39:30 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

static int strres(t_war *name, int i, char *tmp)
{
	char *res;

	res = NULL;
	while (read(name->fd, tmp, 1) > 0 && (i <= PROG_NAME_LENGTH) && tmp[0] != 0)
	{
		if (res == NULL)
			res = ft_strdup((char *)name->buf);
		else
		{
			free(res);
			res = ft_strdup(name->str);
			free(name->str);
		}
		name->str = ft_strjoin(res, tmp);
		i++;
	}
	free(res);
	return (i);
}

header_t	*get_name(t_war name, header_t *head, int ac)
{
	int i;
	char *tmp;

	tmp = ft_strnew(1);
	i = 0;
	i = strres(&name, i, tmp);
	while (i <= (PROG_NAME_LENGTH + 4) && read(name.fd, tmp, 1) > 0)
		i++;
	if (i != (PROG_NAME_LENGTH + 5))
	{
		ft_printf("File ----- us too small to be a champion");
		return (NULL);
	}
	name.buf[0] = tmp[0];
	ft_strcpy(head[ac].prog_name, name.str);
	free(tmp);
	free(name.str);
	name.str = NULL;
	return (size_prog(name, head, ac));
}
