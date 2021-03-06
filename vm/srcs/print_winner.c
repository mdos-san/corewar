/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_winner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 11:38:06 by mdos-san          #+#    #+#             */
/*   Updated: 2017/03/03 12:51:18 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	get_winner(t_cw *cw, int max_last_live, int champ_off, int win)
{
	if (0 <= champ_off && champ_off <= 3
	&& cw->champs[champ_off].path != NULL)
	{
		if (max_last_live < cw->champs[champ_off].last_live)
		{
			max_last_live = cw->champs[champ_off].last_live;
			win = champ_off;
		}
		return (get_winner(cw, max_last_live, champ_off + 1, win));
	}
	else
		return (win);
}

void		print_winner(t_cw *cw)
{
	int	champ_off;

	champ_off = get_winner(cw, 0, 0, 0);
	ft_printf("Contestant %d, \"%s\", has won !\n",
	champ_off + 1, cw->champs[champ_off].h.prog_name);
}
