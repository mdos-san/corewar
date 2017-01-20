/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdorey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 19:15:30 by tdorey            #+#    #+#             */
/*   Updated: 2017/01/17 19:15:34 by tdorey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	set_add_sub(t_process *ptr, int nb, int bin)
{
	int a;
	int b;
	unsigned int *st;

	b = (int)(ptr->data[1]);
	a = (int)*(ptr->data);
	st = ptr->reg + REG_SIZE * (nb - 1);
	if (bin == 0)
		*st = (unsigned int)((a + b) / 4) % IDX_MOD;
	else
		*st = (unsigned int)((a - b) / 4) % IDX_MOD;
}

void	add(t_war *var, t_process *ptr)
{
	char *bin;
	char tab[4];
	int er;

	er = 0;
	ft_bzero(tab, 4);//
	ptr->pc_tmp = (ptr->PC + 4) % SIZE_MAP; // get octet de codage
	bin = ft_itoa_base(*(var->map[ptr->pc_tmp]), 2); //fonction differente avec remplissage en 0
	get_typ(tab, bin, ptr, 0);
	free(bin);
	if (verif_type(tab, var->set + sizeof(t_op) * 3) == 0) // decalage sur structure de l'instruct ( rappel: les datas snt allouées à la suite)
		ptr->PC = (ptr->PC + 8) % SIZE_MAP;  //val a trouver -->decalage vers prochaine instruction
	else
	{
		get_val(tab, var->map, 0, ptr);
		er += replace_reg(ptr, 1);
		er += replace_reg(ptr, 2);
		if (ptr->data[2] != 0 && ptr->data[2] <= REG_NUMBER && er == 0) // registre invalide
			set_add_sub(ptr, (int)ptr->data[2], 0);
		ptr->PC = (ptr->PC + ptr->decal_arg * 4) % SIZE_MAP;//
	}
}

void	sub(t_war *var, t_process *ptr)
{
	char *bin;
	char tab[4];
	int er;

	er = 0;
	ft_bzero(tab, 4);//
	ptr->pc_tmp = (ptr->PC + 4) % SIZE_MAP; // get octet de codage
	bin = ft_itoa_base(*(var->map[ptr->pc_tmp]), 2); //fonction differente avec remplissage en 0
	get_typ(tab, bin, ptr, 0);
	free(bin);
	if (verif_type(tab, var->set + sizeof(t_op) * 3) == 0) // decalage sur structure de l'instruct ( rappel: les datas snt allouées à la suite)
		ptr->PC = (ptr->PC + 8) % SIZE_MAP;  //val a trouver -->decalage vers prochaine instruction
	else
	{
		get_val(tab, var->map, 0, ptr);
		er += replace_reg(ptr, 1);
		er += replace_reg(ptr, 2);
		if (ptr->data[2] != 0 && ptr->data[2] <= REG_NUMBER && er == 0) // registre invalide
			set_add_sub(ptr, ptr->data[2], 1);
		ptr->PC = (ptr->PC + ptr->decal_arg * 4) % SIZE_MAP;//
	}
}