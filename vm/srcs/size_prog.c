/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:39:55 by jcao              #+#    #+#             */
/*   Updated: 2016/12/03 16:48:29 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

header_t	*size_prog(t_war prog, header_t *head, int ac)
{
	int i;
	char *octet1;
	char *octet2;
	char *tmp;
	
	tmp = NULL;
	octet1 = NULL;
	octet2 = NULL;
	i = 0;
	octet1 = ft_itoa_base(prog.buf[0], 2);
	if (read(prog.fd, prog.buf, 1) > 0)
	{
		octet2 = ft_itoa_base(prog.buf[0], 2);
		tmp = ft_strjoin(octet1, octet2);
		i = ft_atoi_base(tmp, 2);
		head[ac].prog_size = i;
	}
	else
		return (NULL);
	free(octet1);
	free(octet2);
	free(tmp);
	return (get_comment(prog, head, ac));
}
