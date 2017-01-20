/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simpl_instruc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdorey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:36:04 by tdorey            #+#    #+#             */
/*   Updated: 2017/01/17 16:36:05 by tdorey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	zjmp (t_war *var, t_process *ptr)
{
	unsigned short	j;
	int st;

	if (ptr->carry == 0)
		ptr->PC = (ptr->PC + 4) % SIZE_MAP;
	else
	{
		*(((char *)&j)) = var->map[(ptr->PC + 4) % SIZE_MAP]; //verif orientation
		*(((char *)&j) + 1) = var->map[(ptr->PC + 8) % SIZE_MAP];
		if (j > 32767)
		{
			st = (ptr->PC - ((65536 - j) % IDX_MOD) * 4); // verif
			ptr->PC = (st < 0) ? SIZE_MAP + st : st;
		}
		else
			ptr->PC = (ptr->PC + (j % IDX_MOD) * 4) % SIZE_MAP;
	}
}

void	fork(t_war *var, t_process *ptr)
{
	t_process *add;
	int st;

	ptr->pc_tmp = (ptr->PC + 4) % SIZE_MAP;
	fill_data(DIR_SIZE / 2, var->map, ptr, 0);
	add = var->proc;
	var->proc = (t_process *)malloc(sizeof(t_process));
	(var->proc)->next = add;
	(var->proc)->carry = ptr->carry; // verif
	(var->proc)->live = 0;//ptr->live; // verif
	(var->proc)->is_waiting = 0;
	(var->proc)->num_champ = ptr->num_champ;
	ft_strncpy((var->proc)->reg, ptr->reg, REG_SIZE * REG_NUMBER);
	//cpy_proc((var->proc)->reg, ptr->reg); // cpy reg
	if (*(ptr->data) > 32767)
	{
		st = (ptr->PC - ((65536 - *(ptr->data)) % IDX_MOD) * 4); // verif
		(var->proc)->PC = (st < 0) ? SIZE_MAP + st : st;
	}
	else
		(var->proc)->PC = (ptr->PC + (*(ptr->data) % IDX_MOD) * 4) % SIZE_MAP;
	var->nb_process++;
	ptr->PC = (ptr->PC + 16) % SIZE_MAP; // decalage op_code + DIR_SIZE / 2 + 1 (next op)
}

void	lfork(t_war *var, t_process *ptr)
{
	t_process *add;
	int st;

	ptr->pc_tmp = (ptr->PC + 4) % SIZE_MAP;
	fill_data(DIR_SIZE / 2, var->map, ptr, 0);
	add = var->proc;
	var->proc = (t_process *)malloc(sizeof(t_process));
	(var->proc)->next = add;
	(var->proc)->carry = ptr->carry; // verif
	(var->proc)->live = 0;//ptr->live; // verif
	(var->proc)->is_waiting = 0;
	(var->proc)->num_champ = ptr->num_champ;
	ft_strncpy((var->proc)->reg, ptr->reg, REG_SIZE * REG_NUMBER);
	if (*(ptr->data) > 32767)
	{
		st = (ptr->PC - (65536 - *(ptr->data)) * 4); // verif
		(var->proc)->PC = (st < 0) ? SIZE_MAP + st : st;
	}
	else
		(var->proc)->PC = (ptr->PC + *(ptr->data) * 4) % SIZE_MAP;
	var->nb_process++;
	ptr->PC = (ptr->PC + 16) % SIZE_MAP; // decalage op_code + DIR_SIZE / 2 + 1 (next op)
}

void	aff(t_war *var, t_process *ptr)
{
	char *bin;

	ptr->pc_tmp = (ptr->tmp + 4) % SIZE_MAP;
	if (*(ptr->pc_tmp) != 1)
		ptr->PC = (ptr->PC + 4) % SIZE_MAP;  //val a trouver -->decalage vers prochaine instruction
	else
	{
		ptr->pc_tmp = (ptr->tmp + 4) % SIZE_MAP;
		fill_data(REG_SIZE, var->map, ptr, 0);
		*(ptr->data) = *(ptr->data) % 256;
		write(1, ptr->data, 1);
		ptr->PC = (ptr->PC + 24) % SIZE_MAP; // opcode + regsize + 1
	}
}

void	live(t_war *var, t_process *ptr)
{
	header_t *tmp;

	fill_data(DIR_SIZE, var->map, ptr, 0);
	if (*(ptr->data) != 0 && *(ptr->data) <= var->nb_champ)
	{
		tmp = var->head_lnk + sizeof(header_t) * (*(ptr->data) - 1);
		tmp->live++;
		tmp->total_live++;
		var->last_live = *(ptr->data);
		var->total_live++;
		var->current_lives;
		ptr->live++;
	}
	ptr->PC = (ptr->PC + 8) % SIZE_MAP;
}