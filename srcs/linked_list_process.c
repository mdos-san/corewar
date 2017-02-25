#include "corewar.h"

static void	reg_init(int *r)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		r[i] = 0;
		++i;
	}
}

t_process *process_new(t_process **act, int champ, int pc, int color_nb)
{
	t_process	*new;

	new = (t_process*)malloc(sizeof(t_process));
	new->nb_champ = champ;
	new->pc = pc;
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
	new->next = NULL;
	reg_init(new->r);
	new->r[0] = champ;
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
