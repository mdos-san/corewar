#include "corewar.h"

void	useless(t_cw *cw, t_process *process)
{
	(void)cw;
	(void)process;
}

void	live(t_cw *cw, t_process *p)
{
	if (!p->is_waiting) 
	{
		++p->is_waiting;
		p->waiting_turn = 10;
	}
	else
	{
		if (p->waiting_turn == 0)
		{
			p->pc += 4 + 1;
			p->is_waiting = 0;
		}
		--p->waiting_turn;
	}
	(void)cw;
}

void	zjmp(t_cw *cw, t_process *p)
{
	unsigned short	j;

	if (!p->is_waiting)
	{
		++p->is_waiting;
		p->waiting_turn = 20;
	}
	else
	{
		if (p->waiting_turn == 0)
		{
			ft_printf("1: %d 2: %d\n", cw->board[p->pc + 1], cw->board[p->pc + 2]);
			*(((char *)&j) + 1) = cw->board[p->pc + 1];
			*(((char *)&j)) = cw->board[p->pc + 2];
			ft_printf("short : %d\n", sizeof(short));
			ft_printf("jmp %d\n", j - 65535);
			if (j > 32768)
				p->pc += j - 65535 - 1;
			else
				p->pc += j;
			p->is_waiting = 0;
		}
		--p->waiting_turn;
	}

}

static int	is_useless(unsigned char c)
{
	if (c == 1 || c == 9)
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
	cw.fct_tab[1] = live;
	cw.fct_tab[9] = zjmp;
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
			{
				ft_printf("-> is useless\n");
				p->pc++;
			}
			else
			{
				(cw.fct_tab[cw.board[p->pc]])(&cw, p);
			}
			if (p->pc == MEM_SIZE)
				p->pc = 0;
			l = l->next;
		}
		usleep(100000);
		++turn;
	}
	(cw.board) ? free(cw.board) : (void)0;
	return (1);
}