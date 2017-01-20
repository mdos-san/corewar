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

void	get_comment(t_war *var, header_t *head, int elem)
{
	int i;
	char c;
	char *ptr;
	header_t *h_ptr;

	h_ptr = head + elem * sizeof(header_t);
	ptr = h_ptr->comment;
	i = 0;
	while (i <= COMMENT_LENGTH && read(var->fd, ptr[i], 1) > 0 && ptr[i] != 0) // verif stop saisie au premier \0
		i++;
	while (i <= COMMENT_LENGTH && read(var->fd, &c, 1) > 0)
		i++;
	if (i != (COMMENT_LENGTH + 1))
	{
		ft_printf("comment: File %s is too small to be a champion\n", var->list_champ[elem]); //sortie d'erreur
		exit();
	}
}
