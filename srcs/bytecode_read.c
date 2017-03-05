/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytecode_read.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 11:27:43 by mdos-san          #+#    #+#             */
/*   Updated: 2017/03/03 13:51:44 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**|	bytecode_read
**|
**|	fonction qui permet de lire le bytecode d'un fichier passé par cw->av
*/

static void	recur(t_cw *cw, unsigned int *j, int i)
{
	if (read(cw->fd, cw->buf, 1) > 0)
	{
		if (0 <= i && i < 4)
			((unsigned char*)(&cw->h->magic))[3 - i] = cw->buf[0];
		if (i >= 4 && i < 4 + PROG_NAME_LENGTH)
			cw->h->prog_name[i - 4] = cw->buf[0];
		else if (i >= 4 + PROG_NAME_LENGTH + 4
				&& i < 4 + PROG_NAME_LENGTH + 8)
		{
			((unsigned char *)(&cw->h->prog_size))[cw->len_offset] = cw->buf[0];
			cw->len_offset -= 1;
		}
		else if (i >= 4 + PROG_NAME_LENGTH + 8
		&& i < 4 + PROG_NAME_LENGTH + 8 + COMMENT_LENGTH)
			cw->h->comment[i - (4 + PROG_NAME_LENGTH + 8)] = cw->buf[0];
		else if (i >= 4 + PROG_NAME_LENGTH + 8 + COMMENT_LENGTH + 4)
		{
			cw->board[mod(*j, cw->index)] = (unsigned char)cw->buf[0];
			cw->board_color[mod(*j, cw->index)] = (unsigned char)cw->color_nb;
			++*j;
			if (*j > cw->h->prog_size)
				exit(0);
		}
		recur(cw, j, ++i);
	}
}

int			bytecode_read(t_cw *cw, char *file, int index, int color_nb)
{
	static int		call = 0;
	unsigned int	j;

	j = 0;
	cw->len_offset = 3;
	cw->h = &cw->champs[call].h;
	cw->fd = open(file, O_RDONLY);
	cw->index = index;
	cw->color_nb = color_nb;
	if (cw->fd == -1)
		return (-1);
	else
	{
		recur(cw, &j, 0);
		if (j != cw->h->prog_size)
			exit(0);
		ft_printf("weighing %ld bytes, \"%s\" (\"%s\") !",
		cw->h->prog_size, cw->h->prog_name, cw->h->comment);
		if (cw->h->magic != COREWAR_EXEC_MAGIC)
			exit(0);
		if (call < 3)
			++call;
		return (1);
	}
}
