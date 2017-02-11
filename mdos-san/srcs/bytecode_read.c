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

static long swap_long(long i)
{
	long r;

	r = 0;
	((char*)(&r))[0] = ((char*)(&i))[7];
	((char*)(&r))[1] = ((char*)(&i))[6];
	((char*)(&r))[2] = ((char*)(&i))[5];
	((char*)(&r))[3] = ((char*)(&i))[4];
	((char*)(&r))[4] = ((char*)(&i))[3];
	((char*)(&r))[5] = ((char*)(&i))[2];
	((char*)(&r))[6] = ((char*)(&i))[1];
	((char*)(&r))[7] = ((char*)(&i))[0];
	return (r);
}

int	bytecode_read(t_cw *cw, char *file, int	index, int color_nb)
{
	int				fd;
	unsigned char	buf[1];
	int				i;
	int				j;
	long			len;
	char			*name;
	char			*comment;

	i = 0;
	j = 0;
	len = 0;
	name = ft_strnew(PROG_NAME_LENGTH);
	comment = ft_strnew(COMMENT_LENGTH);
	fd = open(file, O_RDONLY);	
	if (fd == -1)
	{
		ft_printf("\nERROR: Can't read source file %s\n", file);
		exit(0);
		return (-1);
	}
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
				((char *)(&len))[i - (4 + PROG_NAME_LENGTH)] = buf[0];
			}
			else if (i >= 4 + PROG_NAME_LENGTH + 8 && i < 4 + PROG_NAME_LENGTH + 8 + COMMENT_LENGTH)
				comment[i - (4 + PROG_NAME_LENGTH + 8)] = buf[0];
			else if (i >= 4 + PROG_NAME_LENGTH + 8 + COMMENT_LENGTH + 4)
			{
				cw->board[j + index] = buf[0];
				cw->board_color[j + index] = color_nb;
				++j;
			}
			++i;
		}
		ft_printf("weighing %ld bytes, \"%s\" (\"%s\")", swap_long(len), name, comment);
		return (1);
	}
}
