/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdorey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 15:13:07 by tdorey            #+#    #+#             */
/*   Updated: 2017/01/09 15:13:07 by tdorey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"


int	replace_reg(t_process *ptr, int nb)
{
	char *reg;
	char *tmp;
	unsigned int i;

	i = ptr->data[nb - 1];
	if (i != 0 && i <= 16)
	{
		reg = ptr->reg + REG_SIZE * (i - 1);
		ft_strncpy(&(ptr->data[nb - 1]), reg, REG_SIZE);
		return (0);
	}
	return (1);
}

void	 	fill_data(int size, char *map, t_process *ptr, int index)
{
	int i;
	unsigned int *elem;

	elem = ptr->data + index * sizeof(unsigned int);
	i = sizeof(unsigned int) - size;
	*elem = 0;
	while (size) // ecrire dans val bufferisé
	{
		*((char)(elem + i)) = map[ptr->pc_tmp];
		ptr->pc_tmp = (ptr->pc_tmp + 4) % SIZE_MAP;
		size--;
		i++;
	}
}

void 	get_val(char *tab, char *map, int label, t_process *ptr)
{
	int i;
	int index;

	index = 0;
	i = data->nb_arg;
	ptr->pc_tmp = (ptr->pc_tmp + 4) % SIZE_MAP;
	while (i)
	{
		if (*tab == '1')
			fill_data(1, map, ptr, index); //recuperer nb de registre sur un seul octet seulement
		else if (*tab == '2')
			fill_data(DIR_SIZE / (1 + label), map, ptr, index);
		else if (*tab == '3')
			fill_data(IND_SIZE, map, ptr, index);
		index++;
		tab++;
		i--;
	}
}

long int	get_adre(t_process *ptr, char *tab, int sum, int label)
{
	long int val;
	unsigned int *data;

	data = ptr->data;
	val = 0;
	while (sum)
	{
		if (*tab == '1' || (*tab == '2' && label == 0))
			val += (*data > 2147483647) ? *data - 4294967296 : *data;
		else if (*tab == '3' || (*tab == '2' && label == 1))
			val += (*data > 32767) ? *data - 65536 : *data;
		data++;
		tab++;
		summ--;
	}

	return (val * 4);
}

void 	set_adress_sti(int size, t_process *ptr, char *map, char *tab)
{
	int st;
	char *reg;
	long int adr;

	adr = get_adre(ptr, tab + 1, 2, 1);
	reg = ptr->reg + REG_SIZE * (ptr->data[0] - 1); // set pointeur sur le bon registre
	if (adr < 0)
	{
		st = ptr->PC - (-adr % IDX_MOD);
		ptr->pc_tmp = (st < 0) ? SIZE_MAP + st : st; 
	}
	else
		ptr->pc_tmp = (ptr->PC + adr % IDX_MOD) % SIZE_MAP;
	while (size) // ecrire dans val bufferisé
	{
		var->map[ptr->pc_tmp] = *reg;
		ptr->pc_tmp = (ptr->pc_tmp + 4) % SIZE_MAP;
		size--;
		reg++;
	}
}

void	sti(t_war *var, t_process *ptr)
{
	char *bin;
	char tab[4];

	ft_bzero(tab, 4);//
	ptr->pc_tmp = (ptr->PC + 4) % SIZE_MAP;
	bin = ft_itoa_base(*(var->map[ptr->pc_tmp]), 2); //fonction differente avec remplissage en 0
	get_typ(tab, bin, ptr, 1);
	free(bin);
	if (verif_type(tab, var->set + sizeof(t_op) * 10) == 0) // decalage sur structure de l'instruct ( rappel: les datas snt allouées à la suite)
		ptr->PC = (ptr->PC + 8) % SIZE_MAP;  //val a trouver -->decalage vers prochaine instruction
	else
	{
		get_val(tab, var->map, 1, ptr);
		if (*(tab + 1) == '1')
			er += replace_reg(ptr, 2);
		if (*(tab + 2) == '1')
			er += replace_reg(ptr, 3);
		if (ptr->data[0] != 0 && ptr->data[0] <= 16 && er == 0) // registre invalide
			set_adress_sti(REG_SIZE, ptr, var->map, tab);
		ptr->PC = (ptr->PC + ptr->decal_arg * 4) % SIZE_MAP;//
	}
}

void 	set_adress_ldi(int size, t_process *ptr, char *map, char *tab)
{
	char *reg;
	int st;
	long int adr;

	adr = get_adre(ptr, tab, 2, 1);
	reg = ptr->reg + REG_SIZE * (ptr->data[2] - 1); // set pointeur sur le bon registre
	if (adr < 0)
	{
		st = ptr->PC - (-adr % IDX_MOD);
		ptr->pc_tmp = (st < 0) ? SIZE_MAP + st : st; 
	}
	else
		ptr->pc_tmp = (ptr->PC + adr % IDX_MOD) % SIZE_MAP;
	i = 0;
	while (size) // ecrire dans val bufferisé
	{
		*reg = var->map[ptr->pc_tmp];
		ptr->pc_tmp = (ptr->pc_tmp + 4) % SIZE_MAP;
		size--;
		reg++;
	}
}

void	ldi(t_war *var, t_process *ptr)
{
	char *bin;
	char tab[4];

	ft_bzero(tab, 4);//

	ptr->pc_tmp = (ptr->PC + 4) % SIZE_MAP; // get octet de codage
	bin = ft_itoa_base(*(var->map[ptr->pc_tmp]), 2); //fonction differente avec remplissage en 0
	get_typ(tab, bin, ptr, 1);
	free(bin);
	if (verif_type(tab, var->set + sizeof(t_op) * 9) == 0) // decalage sur structure de l'instruct ( rappel: les datas snt allouées à la suite)
		ptr->PC = (ptr->PC + 8) % SIZE_MAP;  //val a trouver -->decalage vers prochaine instruction
	else
	{
		get_val(tab, var->map, 1, ptr);
		if (*tab == '1')
			er += replace_reg(ptr, 1);
		if (*(tab + 1) == '1')
			er += replace_reg(ptr, 2);
		if (ptr->data[2] != 0 && ptr->data[2] <= REG_NUMBER && er == 0) // registre invalide
			set_adress_ldi(REG_SIZE, ptr, var->map, tab); // verif adress par somme
		ptr->PC = (ptr->PC + ptr->decal_arg * 4) % SIZE_MAP;//
	}
}

void 	set_adress_lldi(int size, t_process *ptr, char *map, char *tab)
{
	char *reg;
	int st;
	long int adr;

	adr = get_adre(ptr, tab, 2, 1);
	reg = ptr->reg + REG_SIZE * (ptr->data[2] - 1); // set pointeur sur le bon registre
	if (adr < 0)
	{
		st = ptr->PC + adr;
		ptr->pc_tmp = (st < 0) ? SIZE_MAP + st : st; 
	}
	else
		ptr->pc_tmp = (ptr->PC + adr) % SIZE_MAP;
	i = 0;
	while (size) // ecrire dans val bufferisé
	{
		*reg = var->map[ptr->pc_tmp];
		ptr->pc_tmp = (ptr->pc_tmp + 4) % SIZE_MAP;
		size--;
		reg++;
	}
}

void	lldi(t_war *var, t_process *ptr)
{
	char *bin;
	char tab[4];

	ft_bzero(tab, 4);//

	ptr->pc_tmp = (ptr->PC + 4) % SIZE_MAP; // get octet de codage
	bin = ft_itoa_base(*(var->map[ptr->pc_tmp]), 2); //fonction differente avec remplissage en 0
	get_typ(tab, bin, ptr, 1);
	free(bin);
	if (verif_type(tab, var->set + sizeof(t_op) * 13) == 0) // decalage sur structure de l'instruct ( rappel: les datas snt allouées à la suite)
		ptr->PC = (ptr->PC + 8) % SIZE_MAP;  //val a trouver -->decalage vers prochaine instruction
	else
	{
		get_val(tab, var->map, 1, ptr);
		if (*tab == '1')
			er += replace_reg(ptr, 1);
		if (*(tab + 1) == '1')
			er += replace_reg(ptr, 2);
		if (ptr->data[2] != 0 && ptr->data[2] <= 16 && er == 0) // registre invalide
		{
			set_adress_lldi(REG_SIZE, ptr, var->map, tab); // verif adress par somme
			ptr->carry = 1;
		}
		ptr->PC = (ptr->PC + ptr->decal_arg * 4) % SIZE_MAP;//
	}
}





