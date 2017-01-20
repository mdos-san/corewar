/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdorey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:17:11 by tdorey            #+#    #+#             */
/*   Updated: 2017/01/18 15:17:13 by tdorey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	and(t_war *var, t_process *ptr)
{
	char *bin;
	char tab[4];
	int er;
	unsigned int tmp;

	ft_bzero(tab, 4);//
	ptr->pc_tmp = (ptr->PC + 4) % SIZE_MAP; // get octet de codage
	bin = ft_itoa_base(*(var->map[ptr->pc_tmp]), 2); //fonction differente avec remplissage en 0
	get_typ(tab, bin, ptr, 0);
	free(bin);
	if (verif_type(tab, var->set + sizeof(t_op) * 5) == 0) // decalage sur structure de l'instruct ( rappel: les datas snt allouées à la suite)
		ptr->PC = (ptr->PC + 8) % SIZE_MAP;  //val a trouver -->decalage vers prochaine instruction
	else
	{
		get_val(tab, var->map, 0, ptr);
		if (*tab == '1')
			er += replace_reg(ptr, 1);
		if (*(tab + 1) == '1')
			er += replace_reg(ptr, 2);
		if (ptr->data[2] != 0 && ptr->data[2] <= REG_NUMBER && er == 0) // registre invalide
		{
			tmp = ptr->reg + REG_SIZE * (ptr->data[2] - 1);
			*tmp = (ptr->data[0] & ptr->data[1]);
		}
		ptr->PC = (ptr->PC + ptr->decal_arg * 4) % SIZE_MAP;//
	}
}

void	or(t_war *var, t_process *ptr)
{
	char *bin;
	char tab[4];
	int er;
	unsigned int tmp;

	ft_bzero(tab, 4);//
	ptr->pc_tmp = (ptr->PC + 4) % SIZE_MAP; // get octet de codage
	bin = ft_itoa_base(*(var->map[ptr->pc_tmp]), 2); //fonction differente avec remplissage en 0
	get_typ(tab, bin, ptr, 0);
	free(bin);
	if (verif_type(tab, var->set + sizeof(t_op) * 5) == 0) // decalage sur structure de l'instruct ( rappel: les datas snt allouées à la suite)
		ptr->PC = (ptr->PC + 8) % SIZE_MAP;  //val a trouver -->decalage vers prochaine instruction
	else
	{
		get_val(tab, var->map, 0, ptr);
		if (*tab == '1')
			er += replace_reg(ptr, 1);
		if (*(tab + 1) == '1')
			er += replace_reg(ptr, 2);
		if (ptr->data[2] != 0 && ptr->data[2] <= REG_NUMBER && er == 0) // registre invalide
		{
			tmp = ptr->reg + REG_SIZE * (ptr->data[2] - 1);
			*tmp = (ptr->data[0] | ptr->data[1]);
		}
		ptr->PC = (ptr->PC + ptr->decal_arg * 4) % SIZE_MAP;//
	}
}

void	xor(t_war *var, t_process *ptr)
{
	char *bin;
	char tab[4];
	int er;
	unsigned int tmp;

	ft_bzero(tab, 4);//
	ptr->pc_tmp = (ptr->PC + 4) % SIZE_MAP; // get octet de codage
	bin = ft_itoa_base(*(var->map[ptr->pc_tmp]), 2); //fonction differente avec remplissage en 0
	get_typ(tab, bin, ptr, 0);
	free(bin);
	if (verif_type(tab, var->set + sizeof(t_op) * 5) == 0) // decalage sur structure de l'instruct ( rappel: les datas snt allouées à la suite)
		ptr->PC = (ptr->PC + 8) % SIZE_MAP;  //val a trouver -->decalage vers prochaine instruction
	else
	{
		get_val(tab, var->map, 0, ptr);
		if (*tab == '1')
			er += replace_reg(ptr, 1);
		if (*(tab + 1) == '1')
			er += replace_reg(ptr, 2);
		if (ptr->data[2] != 0 && ptr->data[2] <= REG_NUMBER && er == 0) // registre invalide
		{
			tmp = ptr->reg + REG_SIZE * (ptr->data[2] - 1);
			*tmp = (ptr->data[0] ^ ptr->data[1]);
		}
		ptr->PC = (ptr->PC + ptr->decal_arg * 4) % SIZE_MAP;//
	}
}
