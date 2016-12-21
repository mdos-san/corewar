#include "corewar.h"

static int	is_useless(unsigned char c)
{
	if (c == 1 || c == 9 || c == 12)
		return (0);
	else
		return (1);
}
int main(int ac, char **av)
{
	t_cw	cw;
	t_list	*l;
	t_process *p;
	long long	turn;

	cw = cw_init(ac, av);
	turn = 0;
	bytecode_read(&cw, av[1], 0);
	process_add(&cw, 1, 0);
	bytecode_read(&cw, av[2], MEM_SIZE / 3);
	process_add(&cw, 2, MEM_SIZE / 3);
	bytecode_read(&cw, av[3], (MEM_SIZE / 3) * 2);
	process_add(&cw, 3, (MEM_SIZE / 3) * 2);
	while (cw.process)
	{
		ft_printf("\033[H\033[2J");
		ft_printf("TURN: %lld NB_PROCESS: %lld\n", turn, cw.nb_process);
		l = cw.process;
		board_print(cw);
		while (l)
		{
			p = (t_process*)l->content;
	//		ft_printf("\nProcess number: %lld reading |%.2x| for player %d ", p->nb_process, cw.board[p->pc], p->nb_champ);
			if (is_useless(cw.board[p->pc]))
				p->pc++;
			else
			{
				(cw.fct_tab[cw.board[p->pc]])(&cw, p);
			}
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