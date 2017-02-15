#include "corewar.h"

void process_new(t_process **act, int champ, int pc, int color_nb)
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
	new->p_one = &new->one;
	new->p_two = &new->two;
	new->p_three = &new->three;
	new->one = 0;
	new->two = 0;
	new->three = 0;
	new->color_nb = color_nb;
	ft_bzero(new->r, REG_NUMBER * REG_SIZE);
	if (act == NULL)
		*act = new;
	else
	{
		new->next = *act;
		*act = new;
	}
}

