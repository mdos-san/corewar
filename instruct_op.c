/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdorey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 12:19:15 by tdorey            #+#    #+#             */
/*   Updated: 2017/01/03 12:19:17 by tdorey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	live(t_war *var, t_champ *p)
{
	char get[4];
	int i;

	i = 0;
	while(i != 4)
	{
		p->PC = (ptr->PC == var->map + MEM_SIZE * 4) ? var->map : ptr->PC + 4;
		get[i] = *(p->PC);
		i++;
	}
	// set live de champ a definir --> les clones heritent de live ? 
	p->pc += 4; //5 cases * 4 taille case 
	(void)var;
}

void	ld(t_war *var, t_champ *p)
{
	char *bin;
	char type[3];
	int i;

	i = 0;

	p->PC = (ptr->PC == var->map + MEM_SIZE * 4) ? var->map : ptr->PC + 4;
	bin = itoa_base(*(p->PC), 2);
	while (i < 6)
	{
		if (bin[i] == '0' && bin[i + 1] == '1')
			type[i / 2] = 'r';
		i += 2;
	}

}

void	zjmp(t_war *cw, t_process *p)
{

	if 
	unsigned short	j;

	*(((char *)&j) + 1) = cw->board[p->pc + 1];
	*(((char *)&j)) = cw->board[p->pc + 2];
	if (j > 32768)
		p->pc += j - 65535 - 1;
	else
		p->pc += j;
}

void	frk(t_war *cw, t_champ *p)
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

void	sti(t_war *cw, t_champ *p)
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
