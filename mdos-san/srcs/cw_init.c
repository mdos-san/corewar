#include "corewar.h"

void	useless(t_cw *cw, t_process *process)
{
	(void)cw;
	(void)process;
}

t_cw	cw_init(int ac, char **av)
{
	int		i;
	t_cw	cw;

	cw.debug = DEBUG;
	cw.board = (unsigned char *)malloc(sizeof(unsigned char) * MEM_SIZE);
	cw.ac = ac;
	cw.av = av;
	cw.nb_process = 0;
	cw.process = NULL;
	i = 0;
	while (i < 256)
	{
		cw.fct_tab[i] = useless;	
		++i;
	}
	cw.fct_tab[1] = live;
	cw.fct_tab[9] = zjmp;
	cw.fct_tab[12] = frk;
	return (cw);
}