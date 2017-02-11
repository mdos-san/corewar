/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytecode_read.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 11:27:43 by mdos-san          #+#    #+#             */
/*   Updated: 2017/02/10 11:29:46 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**|	bytecode_read
**|	
**|	fonction qui permet de lire le bytecode d'un fichier passé par cw->av
*/

int	bytecode_read(t_cw *cw, char *file, int	index, int color_nb)
{
	int				fd;
	unsigned char	buf[1];
	int				i;
	int				j;

	i = 0;
	j = 0;
	fd = open(file, O_RDONLY);	
	if (fd == -1)
		return (-1);
	else
	{
		while (read(fd, buf, 1) > 0)
		{
			//Condition to read only champ processus of the file
			//Processus is written in board directly
			if (i >= 4 + PROG_NAME_LENGTH + 8 + COMMENT_LENGTH + 4)
			{
				cw->board[j + index] = buf[0];
				cw->board_color[j + index] = color_nb;
				++j;
			}
			++i;
		}
		return (1);
	}
}
