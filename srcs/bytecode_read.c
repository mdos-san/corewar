/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytecode_read.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 11:27:43 by mdos-san          #+#    #+#             */
/*   Updated: 2017/02/16 14:36:22 by mdos-san         ###   ########.fr       */
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
	char			buf[1];
	int				i;
	int				j;
	int				len_offset;
	long			len;
	char			*name;
	char			*comment;

	i = 0;
	j = 0;
	len = 0;
	len_offset = 0;
	name = ft_strnew(PROG_NAME_LENGTH);
	comment = ft_strnew(COMMENT_LENGTH);
	fd = open(file, O_RDONLY);	
	if (fd == -1)
		return (-1);
	else
	{
		while (read(fd, buf, 1) > 0)
		{
			//Condition to read only champ processus of the file
			//Processus is written in board directly
			if (i >= 4 && i < 4 + PROG_NAME_LENGTH)
				name[i - 4] = buf[0];
			else if (i >= 4 + PROG_NAME_LENGTH && i < 4 + PROG_NAME_LENGTH + 8)
			{
				((char *)(&len))[len_offset] = buf[0];
				len_offset += 1;
			}
			else if (i >= 4 + PROG_NAME_LENGTH + 8 && i < 4 + PROG_NAME_LENGTH + 8 + COMMENT_LENGTH)
				comment[i - (4 + PROG_NAME_LENGTH + 8)] = buf[0];
			else if (i >= 4 + PROG_NAME_LENGTH + 8 + COMMENT_LENGTH + 4)
			{
				cw->board[j + index] = (unsigned char)buf[0];
				cw->board_color[j + index] = (unsigned char)color_nb;
				++j;
			}
			++i;
		}
		ft_printf("weighing %ld bytes, \"%s\" (\"%s\")", len, name, comment);
		return (1);
	}
}
