/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytecode_read.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 11:27:43 by mdos-san          #+#    #+#             */
/*   Updated: 2017/03/06 12:19:51 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	recur(t_cw *cw, unsigned int *j, int i)
{
	if (read(cw->fd, cw->buf, 1) > 0)
	{
		if (0 <= i && i < EXEC_OFFSET)
			((unsigned char*)(&cw->h->magic))[3 - i] = cw->buf[0];
		if (i >= EXEC_OFFSET && i < NAME_OFFSET)
			cw->h->prog_name[i - 4] = cw->buf[0];
		else if (i >= NAME_OFFSET + 4 && i < LEN_OFFSET)
		{
			((unsigned char *)(&cw->h->prog_size))[cw->len_offset] = cw->buf[0];
			--cw->len_offset;
		}
		else if (i >= LEN_OFFSET && i < COMMENT_OFFSET)
			cw->h->comment[i - (4 + PROG_NAME_LENGTH + 8)] = cw->buf[0];
		else if (i >= COMMENT_OFFSET + 4)
		{
			if (!(0 < cw->h->prog_size && cw->h->prog_size <= CHAMP_MAX_SIZE))
				cw_exit(cw, 1, "ERROR: Prog size doesn't match.");
			cw->board[mod(*j, cw->index)] = (unsigned char)cw->buf[0];
			cw->board_color[mod(*j, cw->index)] = (unsigned char)cw->color_nb;
			++*j;
			if (*j > cw->h->prog_size)
				cw_exit(cw, 1, "ERROR: Prog size doesn't match.");
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
			cw_exit(cw, 1, "ERROR: Prog size doesn't match.");
		ft_printf("weighing %ld bytes, \"%s\" (\"%s\") !",
		cw->h->prog_size, cw->h->prog_name, cw->h->comment);
		if (cw->h->magic != COREWAR_EXEC_MAGIC)
			cw_exit(cw, 1, "ERROR: Exec magic doesn't match.");
		if (call < 3)
			++call;
		return (1);
	}
}
