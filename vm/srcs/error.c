/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 14:27:37 by mdos-san          #+#    #+#             */
/*   Updated: 2017/03/06 11:50:08 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	error(t_cw *cw, char *s)
{
	if (cw->f_v)
		endwin();
	ft_printf("ERROR: %s", s);
	ft_putchar('\n');
	cw_exit(cw, 0, NULL);
}