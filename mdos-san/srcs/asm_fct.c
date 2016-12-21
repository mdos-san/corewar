#include "corewar.h"

void	live(t_cw *cw, t_process *p)
{
	p->pc += 4 + 1;
	(void)cw;
}

void	zjmp(t_cw *cw, t_process *p)
{
	unsigned short	j;

	*(((char *)&j) + 1) = cw->board[p->pc + 1];
	*(((char *)&j)) = cw->board[p->pc + 2];
	if (j > 32768)
		p->pc += j - 65535 - 1;
	else
		p->pc += j;
}

void	frk(t_cw *cw, t_process *p)
{
	unsigned short	j;

	*(((char *)&j) + 1) = cw->board[p->pc + 1];
	*(((char *)&j)) = cw->board[p->pc + 2];
	if (j > 32768)
		process_add(cw, p->nb_champ, p->pc + (j - 65535 - 1));
	else
		process_add(cw, p->nb_champ, p->pc + j);
	p->pc += 3;
}

void	sti(t_cw *cw, t_process *p)
{
	int		one;
	int		two;
	int		three;
	int		sum;
	int		i;
	t_ocp	ocp;

	i = 1;
	ocp = ocp_get(cw->board[p->pc + i]);
	++i;
	ocp_parse(cw, p, &i, ocp, &one, &two, &three);
	sum = two + three;
	one = (one < 0) ? 4294967295 + one + 1 : one;
	cw->board[p->pc + sum] = ((unsigned char *)&one)[3];
	cw->board[p->pc + sum + 1] = ((unsigned char *)&one)[2];
	cw->board[p->pc + sum + 2] = ((unsigned char *)&one)[1];
	cw->board[p->pc + sum + 3] = ((unsigned char *)&one)[0];
	p->pc += i;
}

int	get_turn(unsigned char c)
{
	if (c == 1)
		return (10);
	else if (c == 9)
		return (20);
	else if (c == 11)
		return (25);
	else if (c == 12)
		return (800);
	return (1);
}

/*
**	exec
**
**	Fonction "pattern" qui init les valeur du processus pour le faire attendre un certain nombre de tour
**	quand le precessus a attendu le nombre de tour, exec lance la fonction fct pour executer l action a faire par le processus.
**
*/

void	exec(t_cw *cw, t_process *p, void (*fct)(t_cw *, t_process *))
{
	if (!p->is_waiting)
	{
		p->is_waiting = 1;
		p->waiting_turn = get_turn(cw->board[p->pc]);
	}
	else
	{
		if (p->waiting_turn == 0)
		{
			fct(cw, p);
			p->is_waiting = 0;
		}
		--p->waiting_turn;
	}
}
