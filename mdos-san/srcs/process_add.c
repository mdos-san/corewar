#include "corewar.h"

void	process_add(t_cw *cw, int champ, int pc)
{
	t_process	new;

	new.nb_champ = champ;
	new.pc = pc;
	if (cw->process == NULL)
		cw->process = ft_lstnew((void*)(&new), sizeof(t_process));
	else
		ft_lstpushb(cw->process, (void*)(&new), sizeof(t_process));
}