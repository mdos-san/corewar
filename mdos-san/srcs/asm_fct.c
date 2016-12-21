#include "corewar.h"

void	live(t_cw *cw, t_process *p)
{
	p->pc += 4 + 1;
	p->is_waiting = 0;
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
	p->is_waiting = 0;
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
	p->is_waiting = 0;
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

	one = 0;
	two = 0;
	three = 0;
	sum = 0;
	i = 1;
	ocp = ocp_get(cw->board[p->pc + i]);
	++i;
	ft_printf("ON : %.2x \n", cw->board[p->pc + i]);
	one = p->r[cw->board[p->pc + i] - 1];
	++i;
	ft_printf("|%s|%s|%s|\n", ocp.one, ocp.two, ocp.three);
	if (ft_strcmp(ocp.two, "01") == 0)
	{
		two = p->r[cw->board[p->pc + i - 1]];
		++i;
	}
	else if (ft_strcmp(ocp.two, "10") == 0)
	{
		ft_printf("ON : %.2x \n", cw->board[p->pc + i + 1]);
		*((unsigned char *)&two + 1) = cw->board[p->pc + i];
		*((unsigned char *)&two) = cw->board[p->pc + i + 1];
		i += 2;
	}
	ft_printf("two: %d\n", two);
	if (ft_strcmp(ocp.three, "01") == 0)
	{
		three = p->r[cw->board[p->pc + i - 1]];
		++i;
	}
	else if (ft_strcmp(ocp.three, "10") == 0)
	{
		ft_printf("ON : %.2x \n", cw->board[p->pc + i + 1]);
		*((unsigned char *)&three + 1) = cw->board[p->pc + i];
		*((unsigned char *)&three) = cw->board[p->pc + i + 1];
		i += 2;
	}
	ft_printf("three: %d\n", three);
	sum = two + three;
	ft_printf("two: %d three: %d, sum: %d, one: %d\n", two, three, sum, one);
	one = (one < 0) ? 4294967295 + one + 1 : one;
	cw->board[p->pc + sum] = ((unsigned char *)&one)[3];
	cw->board[p->pc + sum + 1] = ((unsigned char *)&one)[2];
	cw->board[p->pc + sum + 2] = ((unsigned char *)&one)[1];
	cw->board[p->pc + sum + 3] = ((unsigned char *)&one)[0];
	p->pc += i;
	p->is_waiting = 0;
	(void)cw;
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
			fct(cw, p);
		--p->waiting_turn;
	}
}
