#include "corewar.h"

static int	is_useless(unsigned char c)
{
	if (c == 1 || c == 9 || c == 12 || c == 11)
		return (0);
	else
		return (1);
}

int main(int ac, char **av)
{
	t_cw		cw;
	t_list		*l;
	t_process	*p;
	long long	turn;

	cw = cw_init(ac, av);
	turn = 0;
	/*
	**	TODO
	**
	**	Systeme qui parse les parametre et qui initialise les premiers processus
	**	voici trois initialisation faite en dur
	*/
	bytecode_read(&cw, av[1], 0);
	process_add(&cw, -1, 0);
	bytecode_read(&cw, av[2], MEM_SIZE / 3);
	process_add(&cw, -2, MEM_SIZE / 3);
	bytecode_read(&cw, av[3], (MEM_SIZE / 3) * 2);
	process_add(&cw, -3, (MEM_SIZE / 3) * 2);
	/*
	**	END TODO 
	*/
	while (cw.process)
	{
		ft_printf("\033[H\033[2J");
		ft_printf("TURN: %lld NB_PROCESS: %lld\n", turn, cw.nb_process);
		l = cw.process;
		board_print(cw);
		while (l)
		{
			p = (t_process*)l->content;
			if (is_useless(cw.board[p->pc]))
				p->pc++;
			else
				exec(&cw, p, cw.fct_tab[cw.board[p->pc]]);
			if (p->pc == MEM_SIZE)
				p->pc = 0;
			l = l->next;
		}
		usleep(50000);
		++turn;
	}
	(cw.board) ? free(cw.board) : (void)0;
	return (1);
}