/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 11:39:50 by mdos-san          #+#    #+#             */
/*   Updated: 2017/03/06 12:22:44 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	process_free(t_process *l)
{
	if (l != NULL)
	{
		process_free(l->next);
		free(l);
		l = NULL;
	}
}

void		cw_exit(t_cw *cw, int error, char *error_msg)
{
	if (cw->f_v)
		endwin();
	if (cw->process != NULL)
	{
		process_free(cw->process);
		cw->process = NULL;
	}
	if (error == 1)
		printf("%s\n", error_msg);
	exit(0);
}
