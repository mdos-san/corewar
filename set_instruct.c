/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_instruct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdorey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 15:52:16 by tdorey            #+#    #+#             */
/*   Updated: 2017/01/10 15:52:16 by tdorey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	call_set_op_tab(t_war *var)
{
	t_op *ptr;

	var->set = malloc(sizeof(t_op) * 16);
	ptr = var->set;
	set_live(ptr);
	set_ld(ptr + sizeof(t_op));
	set_st(ptr + sizeof(t_op) * 2);
	set_add(ptr + sizeof(t_op) * 3);
	set_sub(ptr + sizeof(t_op) * 4);
	set_and(ptr + sizeof(t_op) * 5);
	set_or(ptr + sizeof(t_op) * 6);
	set_xor(ptr + sizeof(t_op) * 7);
	set_zjmp(ptr + sizeof(t_op) * 8);
	set_ldi(ptr + sizeof(t_op) * 9);
	set_sti(ptr + sizeof(t_op) * 10);
	set_fork(ptr + sizeof(t_op) * 11);
	set_lld(ptr + sizeof(t_op) * 12);
	set_lldi(ptr + sizeof(t_op) * 13);
	set_lfork(ptr + sizeof(t_op) * 14);
	set_aff(ptr + sizeof(t_op) * 15);
}

void	set_live(t_op *ptr)
{
	ptr->instruct = ft_strdup("live");
	ptr->nb_arg = 1;
	ptr->typ_arg = (char *)malloc(sizeof(char));
	*(ptr->typ_arg) = T_DIR;
	ptr->nb_instruct = 1;
	ptr->nb_tour = 10;
	ptr->descrip = ft_strdup("alive");
	ptr->bin_octet = 0;
	ptr->label_size = 0;
}

void	set_ld(t_op *ptr)
{
	ptr->instruct = ft_strdup("ld");
	ptr->nb_arg = 2;
	ptr->typ_arg = (char *)malloc(sizeof(char) * 2);
	*(ptr->typ_arg) = T_DIR | T_IND;
	*(ptr->typ_arg + 1) = T_REG;
	ptr->nb_instruct = 2;
	ptr->nb_tour = 5;
	ptr->descrip = ft_strdup("load");
	ptr->bin_octet = 1;
	ptr->label_size = 0;
}

void	set_st(t_op *ptr)
{
	ptr->instruct = ft_strdup("st");
	ptr->nb_arg = 2;
	ptr->typ_arg = (char *)malloc(sizeof(char) * 2);
	*(ptr->typ_arg) = T_REG;
	*(ptr->typ_arg + 1) = T_IND | T_REG;
	ptr->nb_instruct = 3;
	ptr->nb_tour = 5;
	ptr->descrip = ft_strdup("store");
	ptr->bin_octet = 1;
	ptr->label_size = 0;
}

void	set_add(t_op *ptr)
{
	ptr->instruct = ft_strdup("add");
	ptr->nb_arg = 3;
	ptr->typ_arg = (char *)malloc(sizeof(char) * 3);
	*(ptr->typ_arg) = T_REG;
	*(ptr->typ_arg + 1) = T_REG;
	*(ptr->typ_arg + 2) = T_REG;
	ptr->nb_instruct = 4;
	ptr->nb_tour = 10;
	ptr->descrip = ft_strdup("addition");
	ptr->bin_octet = 1;
	ptr->label_size = 0;
}

void	set_sub(t_op *ptr)
{
	ptr->instruct = ft_strdup("sub");
	ptr->nb_arg = 3;
	ptr->typ_arg = (char *)malloc(sizeof(char) * 3);
	*(ptr->typ_arg) = T_REG;
	*(ptr->typ_arg + 1) = T_REG;
	*(ptr->typ_arg + 2) = T_REG;
	ptr->nb_instruct = 5;
	ptr->nb_tour = 10;
	ptr->descrip = ft_strdup("soustraction");
	ptr->bin_octet = 1;
	ptr->label_size = 0;
}

void	set_and(t_op *ptr)
{
	ptr->instruct = ft_strdup("and");
	ptr->nb_arg = 3;
	ptr->typ_arg = (char *)malloc(sizeof(char) * 3);
	*(ptr->typ_arg) = T_REG | T_DIR | T_IND;
	*(ptr->typ_arg + 1) = T_REG | T_IND | T_DIR;
	*(ptr->typ_arg + 2) = T_REG;
	ptr->nb_instruct = 6;
	ptr->nb_tour = 6;
	ptr->descrip = ft_strdup("et (and  r1, r2, r3   r1&r2 -> r3");
	ptr->bin_octet = 1;
	ptr->label_size = 0;
}

void	set_or(t_op *ptr)
{
	ptr->instruct = ft_strdup("or");
	ptr->nb_arg = 3;
	ptr->typ_arg = (char *)malloc(sizeof(char) * 3);
	*(ptr->typ_arg) = T_REG | T_IND | T_DIR;
	*(ptr->typ_arg + 1) = T_REG | T_IND | T_DIR;
	*(ptr->typ_arg + 2) = T_REG;
	ptr->nb_instruct = 7;
	ptr->nb_tour = 6;
	ptr->descrip = ft_strdup("ou  (or   r1, r2, r3   r1 | r2 -> r3");
	ptr->bin_octet = 1;
	ptr->label_size = 0;
}

void	set_xor(t_op *ptr)
{
	ptr->instruct = ft_strdup("xor");
	ptr->nb_arg = 3;
	ptr->typ_arg = (char *)malloc(sizeof(char) * 3);
	*(ptr->typ_arg) = T_REG | T_IND | T_DIR;
	*(ptr->typ_arg + 1) = T_REG | T_IND | T_DIR;
	*(ptr->typ_arg + 2) = T_REG;
	ptr->nb_instruct = 8;
	ptr->nb_tour = 6;
	ptr->descrip = ft_strdup("ou (xor  r1, r2, r3   r1^r2 -> r3");
	ptr->bin_octet = 1;
	ptr->label_size = 0;
}

void	set_zjmp(t_op *ptr)
{
	ptr->instruct = ft_strdup("zjmp");
	ptr->nb_arg = 1;
	ptr->typ_arg = (char *)malloc(sizeof(char));
	*(ptr->typ_arg) = T_DIR;
	ptr->nb_instruct = 9;
	ptr->nb_tour = 20;
	ptr->descrip = ft_strdup("jump if zero");
	ptr->bin_octet = 0;
	ptr->label_size = 1;
}

void	set_ldi(t_op *ptr)
{
	ptr->instruct = ft_strdup("ldi");
	ptr->nb_arg = 3;
	ptr->typ_arg = (char *)malloc(sizeof(char) * 3);
	*(ptr->typ_arg) = T_REG | T_DIR | T_IND;
	*(ptr->typ_arg + 1) = T_REG | T_DIR;
	*(ptr->typ_arg + 2) = T_REG;
	ptr->nb_instruct = 10;
	ptr->nb_tour = 25;
	ptr->descrip = ft_strdup("load index");
	ptr->bin_octet = 1;
	ptr->label_size = 1;
}

void	set_sti(t_op *ptr)
{
	ptr->instruct = ft_strdup("sti");
	ptr->nb_arg = 3;
	ptr->typ_arg = (char *)malloc(sizeof(char) * 3);
	*(ptr->typ_arg) = T_REG;
	*(ptr->typ_arg + 1) = T_REG | T_DIR | T_IND;
	*(ptr->typ_arg + 2) = T_DIR | T_REG;
	ptr->nb_instruct = 11;
	ptr->nb_tour = 25;
	ptr->descrip = ft_strdup("store index");
	ptr->bin_octet = 1;
	ptr->label_size = 1;
}

void	set_fork(t_op *ptr)
{
	ptr->instruct = ft_strdup("fork");
	ptr->nb_arg = 1;
	ptr->typ_arg = (char *)malloc(sizeof(char));
	*(ptr->typ_arg) = T_DIR;
	ptr->nb_instruct = 12;
	ptr->nb_tour = 800;
	ptr->descrip = ft_strdup("fork");
	ptr->bin_octet = 0;
	ptr->label_size = 1;
}

void	set_lld(t_op *ptr)
{
	ptr->instruct = ft_strdup("lld");
	ptr->nb_arg = 2;
	ptr->typ_arg = (char *)malloc(sizeof(char) * 2);
	*(ptr->typ_arg) = T_DIR | T_IND;
	*(ptr->typ_arg + 1) = T_REG;
	ptr->nb_instruct = 13;
	ptr->nb_tour = 10;
	ptr->descrip = ft_strdup("long load");
	ptr->bin_octet = 1;
	ptr->label_size = 0;
}

void	set_lldi(t_op *ptr)
{
	ptr->instruct = ft_strdup("lldi");
	ptr->nb_arg = 3;
	ptr->typ_arg = (char *)malloc(sizeof(char) * 3);
	*(ptr->typ_arg) = T_REG | T_DIR | T_IND;
	*(ptr->typ_arg + 1) = T_DIR | T_REG;
	*(ptr->typ_arg + 2) = T_REG;
	ptr->nb_instruct = 14;
	ptr->nb_tour = 50;
	ptr->descrip = ft_strdup("long load index");
	ptr->bin_octet = 1;
	ptr->label_size = 1;
}

void	set_lfork(t_op *ptr)
{
	ptr->instruct = ft_strdup("lfork");
	ptr->nb_arg = 1;
	ptr->typ_arg = (char *)malloc(sizeof(char));
	*(ptr->typ_arg) = T_DIR;
	ptr->nb_instruct = 15;
	ptr->nb_tour = 1000;
	ptr->descrip = ft_strdup("long fork");
	ptr->bin_octet = 0;
	ptr->label_size = 1;
}
void	set_aff(t_op *ptr)
{
	ptr->instruct = ft_strdup("aff");
	ptr->nb_arg = 1;
	ptr->typ_arg = (char *)malloc(sizeof(char));
	*(ptr->typ_arg) = T_REG;
	ptr->nb_instruct = 16;
	ptr->nb_tour = 2;
	ptr->descrip = ft_strdup("aff");
	ptr->bin_octet = 1;
	ptr->label_size = 0;
}

