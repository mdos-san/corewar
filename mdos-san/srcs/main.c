#include "corewar.h"

int main(int ac, char **av)
{
	t_cw	cw;
	t_list	*l;
	t_process *p;
	long long	turn;

	turn = 0;
	cw.debug = DEBUG;
	cw.board = (unsigned char *)malloc(sizeof(unsigned char) * MEM_SIZE);
	cw.ac = ac;
	cw.av = av;
	cw.nb_process = 0;
	cw.process = NULL;
	bytecode_read(&cw);
	process_add(&cw, 1, 0);
	while (cw.process)
	{
		ft_printf("\033[H\033[2J");
		ft_printf("TURN: %lld\n", turn);
		l = cw.process;
		board_print(cw);
		while (l)
		{
			ft_printf("\nProcess number: %lld reading |%.2x|\n", p->nb_process, cw.board[p->pc]);
			p = (t_process*)l->content;
			p->pc++;
			l = l->next;
		}
		usleep(250000);
		++turn;
	}
	(cw.board) ? free(cw.board) : (void)0;
	return (1);
}