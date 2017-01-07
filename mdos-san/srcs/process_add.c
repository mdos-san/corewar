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

void	process_add(t_cw *cw, int champ, int pc)
{
	t_process	new;

	new.nb_champ = champ;
	new.pc = pc;
	new.nb_process = ++cw->nb_process;
	new.is_waiting = 0;
	new.waiting_turn = 0;
	new.nb_live = 0;
	new.carry = 0;
	ft_bzero(new.r, REG_NUMBER * REG_SIZE);
	new.r[0] = champ;
	if (cw->process == NULL)
		cw->process = ft_lstnew((void*)(&new), sizeof(t_process));
	else
		ft_lstpushb(cw->process, (void*)(&new), sizeof(t_process));
}
