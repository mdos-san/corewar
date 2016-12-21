#include "corewar.h"

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
			*(((char *)&j) + 1) = cw->board[p->pc + 1];
			*(((char *)&j)) = cw->board[p->pc + 2];
			if (j > 32768)
				p->pc += j - 65535 - 1;
			else
				p->pc += j;
			p->is_waiting = 0;
		}
		--p->waiting_turn;
	}

}

void	frk(t_cw *cw, t_process *p)
{
	unsigned short	j;

	if (!p->is_waiting)
	{
		++p->is_waiting;
		p->waiting_turn = 800;
	}
	else
	{
		if (p->waiting_turn == 0)
		{
			*(((char *)&j) + 1) = cw->board[p->pc + 1];
			*(((char *)&j)) = cw->board[p->pc + 2];
			if (j > 32768)
				process_add(cw, p->nb_champ, p->pc + (j - 65535 - 1));
			else
				process_add(cw, p->nb_champ, p->pc + j);
			p->is_waiting = 0;
			p->pc += 3;
		}
		--p->waiting_turn;
	}

}