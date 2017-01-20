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

void	size_prog(t_war *var, header_t *head, int elem)
{
	char *octet1;
	char *octet2;
	char *tmp;
	char c;

	if (read(var->fd, &c, 1) > 0)
		octet1 = ft_itoa_base(c, 2);
	else
	{
		ft_printf("File %s is too small to be a champion\n", var->list_champ[elem]); //sortie d'erreur
		exit();
	}
	if (read(var->fd, &c, 1) > 0)
	{
		octet2 = ft_itoa_base(c, 2);
		tmp = ft_strjoin(octet1, octet2);
		*(head + elem * sizeof(header_t)) = ft_atoi(tmp);//ft_atoi_base(tmp, 2); //verif compil head[elem].prog_size 
	}
	else
		exit();//eror
	free(octet1);
	free(octet2);
	free(tmp);
}
