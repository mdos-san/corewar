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
	cw.cycle_to_die = CYCLE_TO_DIE;
	i = 0;
	/*
	**	Init par defaut toutes les fonctions de fct_tab a useless
	**	pour eviter d eventuelle segfault
	*/
	while (i < 256)
	{
		cw.fct_tab[i] = useless;	
		++i;
	}
	/*
	*|	On init le tableau de pointeur sur fonctions ici
	*|	les fonctions correspondent au commandes asm
	*|	on gere deja 4 presque fonctions yeah!
	*/
	cw.fct_tab[1] = live;
	cw.fct_tab[2] = ld;
	cw.fct_tab[3] = st;
	cw.fct_tab[4] = add;
	cw.fct_tab[6] = cw_and;
	cw.fct_tab[8] = xor;
 	cw.fct_tab[9] = zjmp;
	cw.fct_tab[10] = ldi;
	cw.fct_tab[11] = sti;
	cw.fct_tab[12] = frk;
	return (cw);
}
