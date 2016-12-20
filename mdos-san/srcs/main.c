#include "corewar.h"

void	useless(void)
{

}

static int	is_useless(unsigned char c)
{
	if (c == 1)
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
	int		i;

	turn = 0;
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
	bytecode_read(&cw);
	process_add(&cw, 1, 0);
	while (cw.process)
	{
		ft_printf("\033[H\033[2J");
		ft_printf("TURN: %lld NB_PROCESS: %lld\n", turn, cw.nb_process);
		l = cw.process;
		board_print(cw);
		ft_printf("\n\033[31m-------------------------------------\n");
		while (l)
		{
			p = (t_process*)l->content;
			ft_printf("\nProcess number: %lld reading |%.2x| ", p->nb_process, cw.board[p->pc]);
			if (is_useless(cw.board[p->pc]))
				ft_printf("-> is useless\n");
			p->pc++;
			if (p->pc == MEM_SIZE)
				p->pc = 0;
			l = l->next;
		}
		usleep(500000);
		++turn;
	}
	(cw.board) ? free(cw.board) : (void)0;
	return (1);
}