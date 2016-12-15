/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 12:01:21 by jcao              #+#    #+#             */
/*   Updated: 2016/12/03 17:23:55 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

static int intres(t_war *name, unsigned int i, header_t *head, int ac)
{
	unsigned int k;

	k = 0;
	while (i <= 1)
	{
		i++;
		read(name->fd, name->buf, 1);
	}
	i = 0;
	while (read(name->fd, name->buf, 1) > 0)
	{
		head[ac].prog_exec[i] = name->buf[0];
		i++;
	}
	//ft_printf("%d\n", i);
	return (i);
}

header_t	*get_prog(t_war name, header_t *head, int ac)
{
	unsigned int	i;

//	ft_printf("%d\n", head[ac].prog_size);
	head[ac].prog_exec = (int *)malloc(sizeof(int) * head[ac].prog_size);
	i = 0;
	i = intres(&name, i, head, ac);
//	ft_printf("%d\n", i);
	if (i != (head[ac].prog_size))
	{
		ft_printf("File ----- us");
		return (NULL);
	}
	close(name.fd);
	name.fd = 0;
	free(head[ac].prog_exec);
	free(name.buf);
	//ft_putstr(name.str);
	//ft_printf("%d\n", head[ac].magic);
	//ft_printf("%s\n", head[ac].prog_name);
	return (head);
}
