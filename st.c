/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdorey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 18:19:33 by tdorey            #+#    #+#             */
/*   Updated: 2017/01/17 18:19:36 by tdorey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	replace_reg_st(t_process *ptr)
{
	char *tmp;
	char *tmp_1;

	if (ptr->data[1] != 0 && ptr->data[1] <= 16)
	{
		tmp = ptr->reg + REG_SIZE * (ptr->data[1] - 1);
		tmp_1 = ptr->reg + REG_SIZE * (ptr->data[0] - 1);
		ft_strncpy(tmp, tmp_1, REG_SIZE);
	}
}

void 	set_adress_st(t_process *ptr, char *map)
{
	int st;
	char *reg;
	int st;

	reg = ptr->reg + REG_SIZE * (ptr->data[0] - 1); // set pointeur sur le bon registre
	if (ptr->data[1] > 32767)
	{
		st = (ptr->PC - ((65536 - ptr->data[1]) % IDX_MOD) * 4); // verif
		ptr->pc_tmp = (st < 0) ? SIZE_MAP + st : st;
	}
	else
		ptr->pc_tmp = (ptr->PC + (ptr->data[1] % IDX_MOD) * 4) % SIZE_MAP;
	st = 4;
	while (st) // ecrire dans val bufferisé
	{
		map[ptr->pc_tmp] = *reg;
		ptr->pc_tmp = (ptr->pc_tmp + 4) % SIZE_MAP;
		st--;
		reg++;
	}
}

void	st(t_war *var, t_process *ptr)
{
	char *bin;
	char tab[4];

	ft_bzero(tab, 4);//

	ptr->pc_tmp = (ptr->PC + 4) % SIZE_MAP; // get octet de codage
	bin = ft_itoa_base(*(var->map[ptr->pc_tmp]), 2); //fonction differente avec remplissage en 0
	get_typ(tab, bin, ptr, 0);
	free(bin);
	if (verif_type(tab, var->set + sizeof(t_op) * 2) == 0) // decalage sur structure de l'instruct ( rappel: les datas snt allouées à la suite)
		ptr->PC = (ptr->PC + 8) % SIZE_MAP;  //val a trouver -->decalage vers prochaine instruction
	else
	{
		get_val(tab, var->map, 0, ptr);
		if (ptr->data[0] != 0 && ptr->data[0] <= REG_NUMBER) // registre invalide
		{
			if (tab[1] == '1')
				replace_reg_st(ptr); // remplace nb  reg par sa valeur
			else
				set_adress_st(t_process *ptr, var->map);	
		}
		ptr->PC = (ptr->PC + ptr->decal_arg * 4) % SIZE_MAP;//
	}
}
