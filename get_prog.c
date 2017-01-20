/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 12:01:21 by jcao              #+#    #+#             */
/*   Updated: 2016/12/07 14:23:21 by tdorey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void		get_prog(t_war *var, header_t *head, int elem)
{
	int		i;
	char 	*ptr;
	char 	c;
	header_t *h_ptr;

	h_ptr = head + (elem * sizeof(header_t));
	ptr = h_ptr->prog_exec;
	*ptr = (char*)malloc(sizeof(char) * h_ptr->prog_size + 1); //verif off_by_1
	ptr[sizeof(char) * h_ptr->prog_size] = 0;
	read(var->fd, &c, 1); //check error
	read(var->fd, &c, 1);
	i = 0;
	while ((read(var->fd, ptr[i], 1) > 0) && (i < h_ptr->prog_size))
		i++;
	if (i != h_ptr->prog_size)
	{
		ft_printf("File %s has a code size that differ from what its headers says", var->list_champ[elem]);
		exit();
	}
	close(var->fd); //check error


}