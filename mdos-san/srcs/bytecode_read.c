#include "corewar.h"

int	bytecode_read(t_cw *cw)
{
	int		fd;
	unsigned char	buf[1];

	fd = open(cw->av[1], O_RDONLY);	
	if (fd == -1)
		return (-1);
	else
	{
		while (read(fd, buf, 1) > 0)
		{
			ft_printf("readed byte: |%.2x|\n", buf[0]);
		}
		return (1);
	}
}