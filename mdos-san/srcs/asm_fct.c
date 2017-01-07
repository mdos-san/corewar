#include "corewar.h"

int		add_index_mod(int a, int b)
{
	int	i;

	i = (a + b) % MEM_SIZE;
	return ((i > 0) ? i : MEM_SIZE + i);
}

void	live(t_cw *cw, t_process *p)
{
	p->pc += 4 + 1;
	p->nb_live += 1;
	(void)cw;
}

void	ld(t_cw *cw, t_process *p)
{
	int	*one;
	int	*two;
	int	*three;
	int	i;
	t_ocp ocp;

	one = (int *)malloc(4);
	two = (int *)malloc(4);
	three = (int *)malloc(4);
	i = 1;
	ocp = ocp_get(cw->board[p->pc + i]);
	++i;
	printw("ocp one %s %s %s\n", ocp.one, ocp.two, ocp.three);
	printw("i + 2 %.2x\n", cw->board[p->pc + i + 2]);
	refresh();
//	sleep(1);
	ocp_parse(cw, p, &i, ocp, (int **)&one, (int **)&two, (int **)&three, 0);
//	one[0] = (one[0] < 0) ? 4294967295 + one[0] + 1 : one[0];
	int y;

	y = 0;
	while (y < 16)
	{
		if (p->r + y == two)
		{
			*two = *one;
			printw("ASSIGN %d TO %p THAT IS REG%d reg now EQUAL %d\n", one[0], two, y, *two);
			refresh();
	//		sleep(2);
		}
		++y;
	}
	p->pc = add_index_mod(p->pc, i);
	if (*two == 0)
		p->carry = 1;
	else
		p->carry = 0;
}

void	st(t_cw *cw, t_process *p)
{
	int		*one;
	int		*two;
	int		*three;
	int		i;
	int		tmp;
	t_ocp	ocp;

	one = (int *)malloc(4);
	two = (int *)malloc(4);
	three = (int *)malloc(4);
	i = 1;
	ocp = ocp_get(cw->board[p->pc + i]);
	++i;
	ocp_parse(cw, p, &i, ocp, (int **)&one, (int **)&two, (int **)&three, 1);
	tmp = (one[0] < 0) ? 4294967295 + one[0] + 1 : one[0];
	if (p->nb_champ == -2)
	{
		printw("\nSTI one %d two %d three %d\n", one[0], two[0], three[0]);
		refresh();
	//	sleep(1);
	}
//	printw("\none %d two %d\n", one[0], two[0]);
//	refresh();
//	sleep(3);
	cw->board[add_index_mod(p->pc, two[0] + 0)] = ((char *)(&tmp))[3];
	cw->board[add_index_mod(p->pc, two[0] + 1)] = ((char *)(&tmp))[2];
	cw->board[add_index_mod(p->pc, two[0] + 2)] = ((char *)(&tmp))[1];
	cw->board[add_index_mod(p->pc, two[0] + 3)] = ((char *)(&tmp))[0];
	p->pc = add_index_mod(p->pc, i);
}

void	add(t_cw *cw, t_process *p)
{
	int		*one;
	int		*two;
	int		*three;
	int		tmp;
	int		i;
	t_ocp	ocp;

	one = (int *)malloc(4);
	two = (int *)malloc(4);
	three = (int *)malloc(4);
	i = 1;
	ocp = ocp_get(cw->board[p->pc + i]);
	++i;
	ocp_parse(cw, p, &i, ocp, (int **)&one, (int **)&two, (int **)&three, 1);
//	printw("\none %d two %d\n", one[0], two[0]);
//	refresh();
//	sleep(3);
	tmp = *one + *two;
	if (p->nb_champ == -1)
	{
		printw("\nADD one %d two %d result(three) %d\n", one[0], two[0], tmp);
		refresh();
//		sleep(10);
	}
	*three = tmp;
	p->pc = add_index_mod(p->pc, i);
	if (*three == 0)
		p->carry = 1;
	else
		p->carry = 0;
}

void	cw_and(t_cw *cw, t_process *p)
{
	int		*one;
	int		*two;
	int		*three;
	int		i;
	t_ocp	ocp;

	one = (int *)malloc(4);
	two = (int *)malloc(4);
	three = (int *)malloc(4);
	i = 1;
	ocp = ocp_get(cw->board[p->pc + i]);
	++i;
	ocp_parse(cw, p, &i, ocp, (int **)&one, (int **)&two, (int **)&three, 1);
	printw("\n\nAND ocp: |%S%S%S00| one %d two %d\n", ocp.one, ocp.two, ocp.three, one[0], two[0]);
	if (p->nb_champ == -2)
	{
//		printw("\nAND one %d two %d result %d\n", one[0], two[0], three[0], *one & *two);
//		refresh();
//		sleep(2);
	}
	*three = *one & *two;
	p->pc = add_index_mod(p->pc, i);
	if (*three == 0)
		p->carry = 1;
	else
		p->carry = 0;
}

void	xor(t_cw *cw, t_process *p)
{
	int		*one;
	int		*two;
	int		*three;
	int		i;
	t_ocp	ocp;

	one = (int *)malloc(4);
	two = (int *)malloc(4);
	three = (int *)malloc(4);
	i = 1;
	ocp = ocp_get(cw->board[p->pc + i]);
	++i;
	ocp_parse(cw, p, &i, ocp, (int **)&one, (int **)&two, (int **)&three, 1);
//	printw("\none %d two %d\n", one[0], two[0]);
//	refresh();
//	sleep(3);
//	*one = (one[0] < 0) ? 4294967295 + one[0] + 1 : one[0];
//	*two = (*two < 0) ? 4294967295 + *two + 1 : *two;
	if (p->nb_champ == -1)
	{
		printw("\nXOR one %d two %d result %d\n", one[0], two[0], *one ^ *two);
//		refresh();
//		sleep(1);
	}
	*three = *one ^ *two;
	p->pc = add_index_mod(p->pc, i);
	if (*three == 0)
		p->carry = 1;
	else
		p->carry = 0;
}

void	zjmp(t_cw *cw, t_process *p)
{
	unsigned short	j;

	*(((char *)&j) + 1) = cw->board[p->pc + 1];
	*(((char *)&j)) = cw->board[p->pc + 2];
	if (p->carry == 1)
	{
		if (j > 32768)
			p->pc = add_index_mod(p->pc, j - 65535 - 1);
		else
			p->pc = add_index_mod(p->pc, j);
	}
	else
		p->pc = add_index_mod(p->pc, 3);
}

void	ldi(t_cw *cw, t_process *p)
{
	int	*one;
	int	*two;
	int	*three;
	int	i;
	int	new_addr;
	t_ocp ocp;

	one = (int *)malloc(4);
	two = (int *)malloc(4);
	three = (int *)malloc(4);
	i = 1;
	ocp = ocp_get(cw->board[p->pc + i]);
	++i;
	ocp_parse(cw, p, &i, ocp, (int **)&one, (int **)&two, (int **)&three, 1);
	printw("\none %d two %d three %d\n", *one, *two, *three);
	refresh();
	//sleep(2);
	new_addr = add_index_mod(*one, *two);
	((char *)three)[3] = *(cw->board + add_index_mod(p->pc, new_addr));
	((char *)three)[2] = *(cw->board + add_index_mod(p->pc, new_addr) + 1);
	((char *)three)[1] = *(cw->board + add_index_mod(p->pc, new_addr) + 2);
	((char *)three)[0] = *(cw->board + add_index_mod(p->pc, new_addr) + 3);
	p->pc = (p->pc + i) % MEM_SIZE;
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
	p->pc = add_index_mod(p->pc, 3);
}


void	sti(t_cw *cw, t_process *p)
{
	int		*one;
	int		*two;
	int		*three;
	int		sum;
	int		i;
	t_ocp	ocp;

	one = (int *)malloc(4);
	two = (int *)malloc(4);
	three = (int *)malloc(4);
	i = 1;
	ocp = ocp_get(cw->board[p->pc + i]);
	++i;
	ocp_parse(cw, p, &i, ocp, (int **)&one, (int **)&two, (int **)&three, 1);
	*one = (one[0] < 0) ? 4294967295 + one[0] + 1 : one[0];
	sum = *two + *three;
	if (p->nb_champ == -2 && *one != -2)
	{
		printw("\none %d two %d three %d\n", one[0], two[0], three[0]);
		refresh();
	//	sleep(1);
	}
	cw->board[add_index_mod(p->pc, sum + 0)] = ((char *)(one))[3];
	cw->board[add_index_mod(p->pc, sum + 1)] = ((char *)(one))[2];
	cw->board[add_index_mod(p->pc, sum + 2)] = ((char *)(one))[1];
	cw->board[add_index_mod(p->pc, sum + 3)] = ((char *)(one))[0];
	p->pc = add_index_mod(p->pc, i);
}

int	get_turn(unsigned char c)
{
	if (c == 1)
		return (10);
	else if (c == 2 || c == 3 || c == 4)
		return (5);
	else if (c == 6 || c == 7)
		return (6);
	else if (c == 9)
		return (20);
	else if (c == 10 || c == 11)
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
