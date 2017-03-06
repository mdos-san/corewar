/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seek_instruc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:12:15 by jcao              #+#    #+#             */
/*   Updated: 2017/02/11 16:37:04 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_asm.h"

int				seek_instruc(t_asm *var, char **av)
{
	int res;

	res = 1;
	var->instruc = next_str_spe(var);
	if (var->first == 0)
	{
		res = first_check(var, av);
		var->first = 1;
	}
	else
		res = check_normal(var, av);
	if (res < 0)
		return (res);
	while (var->instruc[0] != '\0' && res > 0)
	{
		free(var->instruc);
		var->instruc = next_str_spe(var);
		res = next_check(var, av);
	}
	return (res);
}
