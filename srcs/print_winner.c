#include "corewar.h"

static int	get_winner(t_cw *cw, int max_last_live, int champ_off, int win)
{
	if (0 <= champ_off && champ_off <= 3)
	{
		if (max_last_live < cw->champs[champ_off].last_live)
		{
			max_last_live = cw->champs[champ_off].last_live;
			win = champ_off;
		}
		if (cw->champs[champ_off].path == NULL)
			--win;
		return (get_winner(cw, max_last_live, champ_off - 1, win));
	}
	else
		return (win);
}

void		print_winner(t_cw *cw)
{
	int	champ_off;

	champ_off = get_winner(cw, 0, 3, 3);
	ft_printf("le joueur %d(%s) a gagne !\n",
	cw->champs[champ_off].number, cw->champs[champ_off].h.prog_name);
}
