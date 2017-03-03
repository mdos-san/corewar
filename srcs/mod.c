/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 14:36:44 by mdos-san          #+#    #+#             */
/*   Updated: 2017/03/03 14:36:54 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		mod(int a, int b)
{
	int	i;

	i = a + b;
	i %= MEM_SIZE;
	if (i < 0)
		i = MEM_SIZE + i;
	return (i);
}

int		idx_mod(int a)
{
	int	n;

	n = (a < 0) ? 1 : 0;
	a *= (a < 0) ? -1 : 1;
	a %= IDX_MOD;
	if (n)
		a *= -1;
	return (a);
}
