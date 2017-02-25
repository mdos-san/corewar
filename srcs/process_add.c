#include "corewar.h"

/*
**|
**|	process_add
**|
**|	
**|	Ajoute un nouveau processus appartenant au champion champ, et commençant a l addresse pc
**|	Le processus est ajouter a la liste chainée des processus.
**|	
**|	
*/

void	process_add(t_cw *cw, int champ, int pc, int color_nb)
{
	t_process	new;

	new.nb_champ = champ;
	new.pc = pc;
	new.nb_process = ++cw->nb_process;
	new.is_waiting = 0;
	new.waiting_turn = 0;
	new.nb_live = 0;
	new.carry = 0;
	new.p_one = &new.one;
	new.p_two = &new.two;
	new.p_three = &new.three;
	new.one = 0;
	new.two = 0;
	new.three = 0;
	new.color_nb = color_nb;
	ft_bzero(new.r, REG_NUMBER * REG_SIZE);
	new.r[0] = champ;
	if (cw->process == NULL)
		cw->process = ft_lstnew((void*)(&new), sizeof(t_process));
	else
		ft_lstpushb(cw->process, (void*)(&new), sizeof(t_process));
}