/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdorey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:13:23 by tdorey            #+#    #+#             */
/*   Updated: 2017/01/18 16:13:27 by tdorey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	set_adress_ld(char c, t_process *ptr, int bin)
{
	int i;
	char *reg;
	char *val_ptr;

	if (bin)
		*(ptr->data) = *(ptr->data) % IDX_MOD;
	val_ptr = ptr->data;
	i = (c == '2') ? DIR_SIZE : IND_SIZE;
	reg = ptr->reg + REG_SIZE * (ptr->data[1] - 1);
	(int)*reg = 0; // set reg to 0
	reg += (c == '2') ? 0 : 2; // decalage sur bon octet
	while (i)
	{
		*reg = *val_ptr;
		reg++;
		val_ptr++;
		i--;
	}
}

void	ld(t_war *var, t_process *ptr)
{
	char tab[4];
	char *bin;

	ft_bzero(tab, 4);
	ptr->pc_tmp = (ptr->tmp + 4) % SIZE_MAP;
	bin = ft_itoa_base(ptr->pc_tmp, 2); //fonction differente avec remplissage en 0
	get_typ(tab, bin, ptr, 0);
	free(bin);
	if (verif_type(tab, var->set + sizeof(t_op)) == 0) // decalage sur structure de l'instruct ( rappel: les datas snt allouées à la suite)
		ptr->PC = (ptr->PC + 8) % SIZE_MAP;  //val a trouver -->decalage vers prochaine instruction
	else
	{
		get_val(tab, var->map, 0, ptr);
		if (ptr->data[1] != 0 && ptr->data[1] <= REG_NUMBER) // registre invalide
		{
			set_adress_ld(*tab, ptr, 1);
			ptr->carry = 1;
		}
		ptr->PC = (ptr->PC + ptr->decal_arg * 4) % SIZE_MAP;
	}
} 

void	lld(t_war *var, t_process *ptr)
{
	char tab[4];
	char *bin;

	ft_bzero(tab, 4);
	ptr->pc_tmp = (ptr->tmp + 4) % SIZE_MAP;
	bin = ft_itoa_base(ptr->pc_tmp, 2); //fonction differente avec remplissage en 0
	get_typ(tab, bin, ptr, 0);
	free(bin);
	if (verif_type(tab, var->set + sizeof(t_op) * 12) == 0) // decalage sur structure de l'instruct ( rappel: les datas snt allouées à la suite)
		ptr->PC = (ptr->PC + 8) % SIZE_MAP;  //val a trouver -->decalage vers prochaine instruction
	else
	{
		get_val(tab, var->map, 0, ptr);
		if (ptr->data[1] != 0 && ptr->data[1] <= REG_NUMBER) // registre invalide
		{
			set_adress_ld(*tab, ptr, 0);
			ptr->carry = 1;
		}
		ptr->PC = (ptr->PC + ptr->decal_arg * 4) % SIZE_MAP;
	}
}
