#include "corewar.h"

/*
**|	bytecode_read
**|	
**|	fonction qui permet de lire le bytecode d'un fichier passé par cw->av
*/

int	bytecode_read(t_cw *cw, char *file, int	index)
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
			if (i >= 4 + 128 + 8 + 2048 + 4)
			{
				cw->board[j + index] = buf[0];
				++j;
			}
			++i;
		}
		return (1);
	}
}