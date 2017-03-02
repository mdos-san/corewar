/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytecode_read.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 11:27:43 by mdos-san          #+#    #+#             */
/*   Updated: 2017/02/28 08:11:50 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**|	bytecode_read
**|
**|	fonction qui permet de lire le bytecode d'un fichier passé par cw->av
*/

int	bytecode_read(t_cw *cw, char *file, int index, int color_nb)
{
	static int		call = 0;
	int				fd;
	char			buf[1];
	int				i;
	unsigned int	j;
	int				len_offset;
	t_header		*h;
	

	i = 0;
	j = 0;
	len_offset = 3;
	h = &cw->champs[call].h;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	else
	{
		while (read(fd, buf, 1) > 0)
		{
			if (i >= 4 && i < 4 + PROG_NAME_LENGTH)
				h->prog_name[i - 4] = buf[0];
			else if (i >= 4 + PROG_NAME_LENGTH + 4
			&& i < 4 + PROG_NAME_LENGTH + 8)
			{
				((unsigned char *)(&h->prog_size))[len_offset] = buf[0];
				len_offset -= 1;
			}
			else if (i >= 4 + PROG_NAME_LENGTH + 8
			&& i < 4 + PROG_NAME_LENGTH + 8 + COMMENT_LENGTH)
				h->comment[i - (4 + PROG_NAME_LENGTH + 8)] = buf[0];
			else if (i >= 4 + PROG_NAME_LENGTH + 8 + COMMENT_LENGTH + 4)
			{
				cw->board[mod(j, index)] = (unsigned char)buf[0];
				cw->board_color[mod(j, index)] = (unsigned char)color_nb;
				++j;
				if (j > h->prog_size)
					exit(0);
			}
			++i;
		}
		if (j != h->prog_size)
			exit(0);
		ft_printf("weighing %ld bytes, \"%s\" (\"%s\") !",
		h->prog_size, h->prog_name, h->comment);
		if (call < 3)
			++call;
		return (1);
	}
}
