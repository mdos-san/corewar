#include "corewar.h"

static void	useless(t_cw *cw, t_process *process)
{
	(void)cw;
	++process->pc;
}

static int	visu_init(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_strcmp(av[i], "-v") == 0)
		{
			initscr();
			noecho();
			curs_set(FALSE);
			start_color();
			init_pair(42, COLOR_WHITE, COLOR_BLACK);
			init_pair(1, COLOR_GREEN, COLOR_BLACK);
			init_pair(2, COLOR_BLUE, COLOR_BLACK);
			init_pair(3, COLOR_RED, COLOR_BLACK);
			init_pair(4, COLOR_YELLOW, COLOR_BLACK);
			init_pair(1 + 4, COLOR_GREEN, COLOR_CYAN);
			init_pair(2 + 4, COLOR_BLUE, COLOR_CYAN);
			init_pair(3 + 4, COLOR_RED, COLOR_CYAN);
			init_pair(4 + 4, COLOR_YELLOW, COLOR_CYAN);
			init_pair(42 + 4, COLOR_WHITE, COLOR_CYAN);
			return (1);
		}
		++i;
	}
	return (0);
}

t_cw	cw_init(int ac, char **av)
{
	int		i;
	t_cw	cw;

	cw.debug = DEBUG;
	cw.board = (unsigned char *)malloc(sizeof(unsigned char) * MEM_SIZE);
	cw.board_color = (unsigned char *)ft_strnew(MEM_SIZE);
	cw.f_v = visu_init(ac, av);
	cw.f_dump = -1;
	cw.ac = ac;
	cw.av = av;
	cw.nb_process = 0;
	cw.process = NULL;
	cw.cycle_to_die = CYCLE_TO_DIE;
	i = 0;
	while (i < 256)
	{
		cw.fct_tab[i] = useless;	
		++i;
	}
	cw.fct_tab[1] = live;
	cw.fct_tab[2] = ld;
	cw.fct_tab[3] = st;
	cw.fct_tab[4] = add;
	cw.fct_tab[5] = sub;
	cw.fct_tab[6] = and;
	cw.fct_tab[6] = or;
	cw.fct_tab[8] = xor;
 	cw.fct_tab[9] = zjmp;
	cw.fct_tab[10] = ldi;
	cw.fct_tab[11] = sti;
	cw.fct_tab[12] = frk;
	return (cw);
}
