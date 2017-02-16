#include "corewar.h"

t_process *process_new(t_process **act, int champ, int pc, int color_nb)
{
	t_process	*new;

	new = (t_process*)malloc(sizeof(t_process));
	new->nb_champ = champ;
	new->pc = pc;
//	new->nb_process = ++cw->nb_process;
	new->is_waiting = 0;
	new->waiting_turn = 0;
	new->nb_live = 0;
	new->carry = 0;
	new->c = 0;
	new->null[0] = &new->c;
	new->three = 0;
	new->color_nb = color_nb;
	ft_bzero(new->r, REG_NUMBER * REG_SIZE);
	new->r[0] = champ;
	new->next = NULL;
	if (*act == NULL)
		*act = new;
	else
	{
		new->next = *act;
		*act = new;
	}
	return (new);
}


int	process_count(t_process *l)
{
	int	i;

	i = 0;
	while (l)
	{
		++i;
		l = l->next;
	}
	return (i);
}
