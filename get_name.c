/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   war_comment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 11:29:12 by jcao              #+#    #+#             */
/*   Updated: 2016/12/05 11:39:30 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	get_name(t_war *var, header_t *head, int elem)
{
	int i;
	char tmp;
	char *ptr;
	header_t *h_ptr;

	h_ptr = head + elem * sizeof(header_t);
	ptr = h_ptr->prog_name;
	i = 0;
	while (read(var->fd, ptr[i], 1) > 0 && (i <= PROG_NAME_LENGTH) && ptr[i] != 0)
		i++;
	while (i < (PROG_NAME_LENGTH + 4) && read(var->fd, &tmp, 1) > 0)
		i++;
}
