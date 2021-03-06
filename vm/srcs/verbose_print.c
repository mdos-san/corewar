/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 09:03:05 by mdos-san          #+#    #+#             */
/*   Updated: 2017/03/03 11:54:49 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	verbose_print(t_cw *cw, int i, int start, int end)
{
	int	j;

	j = start;
	while (j < end)
	{
		ft_printf("%.2x ", cw->board[mod(cw->ap->pc, i + j)]);
		++j;
	}
}
