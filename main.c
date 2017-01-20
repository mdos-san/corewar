/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 13:34:53 by jcao              #+#    #+#             */
/*   Updated: 2016/12/05 11:47:52 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

int corewar_help()
{
	ft_printf("Usage: ./corewar [-dump nbr_cycles] [[-n number] champion1.cor] ");
	ft_printf("...\nAide Corewar:\n\n-dump nbr_cycles : Au bout de nbr_cycles d");
	ft_printf("'exécution, dump la mémoire sur la sortie standard, puis quitte ");
	ft_printf("la partie.\n-n number: Fixe le numéro du prochain joueur. Si abs");
	ft_printf("ent, le joueur aura le prochain numéro dans l'ordre des paramètr");
	ft_printf("es.\n\nCe corewar ne supportera pas plus de 4 champions.\n");
	return (0);
}

void	cpy_int_string(char *ptr, header_t *head)
{
	int i;

	i = 0;
	while (i < head->prog_size)
	{
		ptr[i * 4] = head->prog_exec[i]; //verif compatibilite 
		i++;
	}
}

void	init_fct_array(t_war *cw)
{
	cw->fct_tab[1] = live;
	cw->fct_tab[2] = ld;
	cw->fct_tab[3] = st;
	cw->fct_tab[4] = add;
	cw->fct_tab[5] = sub;
	cw->fct_tab[6] = and;
	cw->fct_tab[7] = or;
	cw->fct_tab[8] = xor;
	cw->fct_tab[9] = zjmp;
	cw->fct_tab[10] = ldi;
	cw->fct_tab[11] = sti;
	cw->fct_tab[12] = frk;
	cw->fct_tab[13] = lld;
	cw->fct_tab[14] = lldi;
	cw->fct_tab[15] = lfork;
	cw->fct_tab[16] = aff;
	cw->CYCLE_TO_DIE = CYCLE_TO_DIE;
	cw->nb_process = var->nb_champ;
}

void	set_champ(t_war *var, header_t *head)
{
	int i;
	t_process *mnp;

	i = 0;
	init_fct_array(var);
	call_set_op_tab(var);
	while (i < var->nb_champ)
	{
		if (i == 0)
			var->proc = (t_process*)malloc(sizeof(t_process));
		else
			mnp->next = (t_process*)malloc(sizeof(t_process));
		mnp = (i == 0) ? var->proc : mnp->next;
		ft_bzero(mnp, sizeof(t_process)); 
		mnp->PC = i * SIZE_MAP / var->nb_champ;
		(unsigned int)*(mnp->reg) = (i + 1); // * -1 si gere en negatif
		mnp->num_champ = i + 1;
		cpy_int_string(&(var->map[mnp->PC]), &(head[i])); // verif head[i]
		var->last_chain = mnp;
		i++;
	}
}

void	verif_live_proc(t_war *var)
{
	t_process *ptr;
	t_process *tmp;
	t_process *next;

	ptr = var->proc;
	tmp = NULL;
	while (ptr)
	{
		next = ptr->next;
		if (!ptr->live)
		{
			if (tmp)
				tmp->next = next;
			else
				var->proc = next;
			free(ptr);
			var->nb_process--;
		}
		else
		{
			ptr->live = 0;
			tmp = ptr;
		}
		ptr = next;
	}
}

void	corewar_fight(t_war *var, header_t *head) // lecture de memoire unitaire 
{
	var->cycle = 0; // init cycle 
	t_process *ptr;

	while (var->nb_process && var->CYCLE_TO_DIE > 0) // tant qu'un champion en vie boucle global a securiser
	{
		ptr = var->proc;
		while (ptr)
		{
			if (*(var->map[ptr->PC]) < 1 || *(var->map[ptr->PC]) > 16) // valeur d'opcode
				ptr->PC = (ptr->PC + 4) % SIZE_MAP;
				//ptr->PC = (ptr->PC == var->map + (MEM_SIZE - 1) * 4) ? var->map : ptr->PC + 4; // cycle memoire  !!global ou stockage pour recalcul rapide 
			else // verif decalage d'octet ou d'instruction
				exec(var, ptr, var->fct_tab[*(var->map[ptr->PC])]); // 
			ptr = ptr->next;
		}
		var->current_cycle++;
		var->total_cycle++;
		if ((var->current_cycle % var->CYCLE_TO_DIE) == 0)
		{
			verif_live_proc(var);
			var->current_cycle = 0;
			if ((var->current_lives >= NBR_LIVE) || var->check == MAX_CHECKS)
			{
				var->CYCLE_TO_DIE -= CYCLE_DELTA;
				var->check = 0;
			}
			else
				var->check++;
		}
	}
}

void	exec(t_war *var,  t_process *p, void (*fct)(t_war *, t_process *))
{
	t_op *ptr;

	if (!p->is_waiting)
	{
		p->is_waiting = 1;
		ptr = var->set + sizeof(t_op) * (*(var->map[ptr->PC]) - 1);
		p->waiting_turn = ptr->nb_tour;//(int)var->set[*(var->map[ptr->PC]) - 1][4]; // verif valid 
	}
	else
	{
		if (p->waiting_turn == 0)
		{
			fct(var, p);
			p->is_waiting = 0;
		}
		--p->waiting_turn; //verif 
	}
}

/*void	get_param(t_war *var)
{

}*/

int	main(int ac, char **av) // Il faut un premier parse de flag ?
{
	t_war		var;
	header_t	*head;
	int			i;

	i = 0;
	if (ac == 1)
		return corewar_help();
	ft_bzero(var, sizeof(t_war));
 	//get_param(&var); 
	 if (var.nb_champ > MAX_PLAYERS + 1) //complement flag // ac => nb elem new tab 
		return (write(1, "Trop de champions\n",18));
	if (!(head = (header_t *)malloc(sizeof(header_t) * (4))))//complement flag
		return (-1);
	ft_bzero(head, sizeof(header_t) * 4);// clear all
	var.head_lnk = head;
	while (var.nb_champ > i) //complement flag + verif 
	{
		check_exec(&var, var.list_champ[i]);
		get_name(&var, head, i);
		size_prog(&var, head, i);
		get_comment(&var, head, i);
		get_prog(&var, head, i); // !! prog_exec rempli en *char
		i++;
	} //ici tous les champions sont valides et dans l'ordre d'exec
	intro_display(var, head);
	set_champ(&var, head); //malloc map + write on map + set t_champ struct 
	corewar_fight(&var, head);
	return (0);
}
