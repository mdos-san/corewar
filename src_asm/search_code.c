/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_code.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:58:45 by ajubert           #+#    #+#             */
/*   Updated: 2017/02/25 13:40:02 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_asm.h"

unsigned char	search_code(char *str, t_e *e)
{
	int i;

	i = 0;
	while (i < NB_OP)
	{
		if (ft_strcmp(str, e->liste_op[i]) == 0)
			return (i + 1);
		i++;
	}
	return (0);
}
