#include "corewar.h"

void get_bin(char *buf, long long nbr, unsigned int base)
{
	int			i;
	long long	mod;
	long long	neg;

	i = 0;
	ft_bzero(buf, 9);
	neg = (nbr < 0) ? -1 : 1;
	while (nbr != 0)
	{
		mod = nbr % base;
		if (mod <= 9)
			buf[7 - i] = mod * neg + 48;
		else
		{
			mod -= 10;
			buf[7 - i] = mod * neg + 97;
		}
		nbr /= base;
		++i;
	}
	while (i < 8)
	{
		buf[7 - i] = '0';
		++i;
	}
}

t_ocp	ocp_get(unsigned char ocp)
{
	char	str[9];
	t_ocp	st;

	get_bin(str, ocp, 2);
	st.one[0] = str[0];
	st.one[1] = str[1];
	st.one[2] = 0;
	st.two[0] = str[2];
	st.two[1] = str[3];
	st.two[2] = 0;
	st.three[0] = str[4];
	st.three[1] = str[5];
	st.three[2] = 0;
	return (st);
}

/*
**	ocp_parse permet de recuperer les bons parametre en fonction de t_ocp ocp
**	les parametres sont initialise dans des int passé en parametre
**	La fonction est juste faite pour sti, des amelioration sont a faire pour quelle soit utilisable dans toute les fonctions
*/

static	void	ocp_part(t_cw *cw, t_process *p, int *i, int *v, int **pt, char *str, int dir_two)
{
	if (ft_strcmp(str, "01") == 0)
	{
		if (1 <= cw->board[p->pc + *i] && cw->board[p->pc + *i] <= 16)
			*pt = p->r + (cw->board[p->pc + *i]) - 1;
		++*i;
	}
	else if (ft_strcmp(str, "11") == 0 || dir_two == 1)
	{
		((unsigned char *)v)[1] = cw->board[p->pc + *i];
		((unsigned char *)v)[0] = cw->board[p->pc + *i + 1];
		*i += 2;
	}
	else if (ft_strcmp(str, "10") == 0)
	{
		((unsigned char *)v)[3] = cw->board[p->pc + *i];
		((unsigned char *)v)[2] = cw->board[p->pc + *i + 1];
		((unsigned char *)v)[1] = cw->board[p->pc + *i + 2];
		((unsigned char *)v)[0] = cw->board[p->pc + *i + 3];
		*i += 4;
	}
}

void	ocp_parse(t_cw *cw, t_process *p, int *i, t_ocp ocp, int dir_two)
{
	p->p_one = &p->one;
	p->p_two = &p->two;
	p->p_three = &p->three;
	p->one = 0;
	p->two = 0;
	p->three = 0;
	ocp_part(cw, p, i, &p->one, &p->p_one, ocp.one, dir_two);
	ocp_part(cw, p, i, &p->two, &p->p_two, ocp.two, dir_two);
	ocp_part(cw, p, i, &p->three, &p->p_three, ocp.three, dir_two);
}
