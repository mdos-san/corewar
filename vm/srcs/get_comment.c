/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_comment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 17:56:12 by jcao              #+#    #+#             */
/*   Updated: 2016/12/05 11:39:40 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

static int strres(t_war *name, int i, char *tmp)
{
	char *res;
	char *malloc;

	res = NULL;
	while (read(name->fd, tmp, 1) > 0 && (i <= COMMENT_LENGTH) && tmp[0] != 0)
	{
		if (name->str == NULL)
			name->str = ft_strdup(tmp);
		else
		{
			res = ft_strdup(name->str);
			free(name->str);
			malloc = ft_strdup(tmp);
			name->str = ft_strjoin(res, malloc);
			free(res);
			free(malloc);
		}
		i++;
	}
	return (i);
}

header_t		*get_comment(t_war name, header_t *head, int ac)
{
	int i;
	char *tmp;
	
	tmp = ft_strnew(2);
	i = 0;
	i = strres(&name, i, tmp);
	while (i <= COMMENT_LENGTH && read(name.fd, tmp, 1) > 0)
		i++;
	if (i != (COMMENT_LENGTH + 1))
	{
		ft_printf("comment: File ----- us too small to be a champion");
		return (NULL);
	}
	ft_strcpy(head[ac].comment, name.str);
	name.buf[0] = tmp[0];
	free(tmp);
	free(name.str);
	return (get_prog(name, head, ac));
}
