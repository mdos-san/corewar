/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 11:20:47 by jcao              #+#    #+#             */
/*   Updated: 2017/02/10 18:03:28 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_asm.h"

int			error_type(t_asm *var, int type, int res)
{
	if (res == -3)
		return (-3);
	else if (res == -2)
		return (-2);
	else if (res == -1)
		return (-1);
	else
	{
		var->type = type;
		var->type_code = res;
	}
	return (-5);
}
