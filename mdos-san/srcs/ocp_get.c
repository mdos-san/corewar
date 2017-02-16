#include "corewar.h"

static void	get_bin(char *buf, int nbr, int base)
{
	int	i;
	int	mod;
	int	neg;

	i = 0;
	ft_bzero(buf, 9);
	neg = (nbr < 0) ? -1 : 1;
	while (nbr != 0)
	{
		mod = nbr % base;
		if (mod <= 9)
			buf[7 - i] = (char)(mod * neg + 48);
		else
		{
			mod -= 10;
			buf[7 - i] = (char)(mod * neg + 97);
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

static	void	ocp_part(t_cw *cw, t_process *p, int *i, unsigned char **v, char *str, int dir_two)
{
	int	ind;
	int	*reg_v;

	ind = 0;
	if (ft_strcmp(str, "01") == 0)
	{
		ft_printf("%.2x ", cw->board[p->pc + *i]);
		if (1 <= cw->board[p->pc + *i] && cw->board[p->pc + *i] <= 16)
		{
			reg_v = p->r + (cw->board[add_index_mod(p->pc, *i)] - 1);
			v[0] = ((unsigned char *)(reg_v)) + 3;
			v[1] = ((unsigned char *)(reg_v)) + 2;
			v[2] = ((unsigned char *)(reg_v)) + 1;
			v[3] = ((unsigned char *)(reg_v)) + 0;
		}
		else
			v[0] = NULL;
		++*i;
	}
	else if (ft_strcmp(str, "11") == 0)
	{
		((unsigned char *)&ind)[1] = cw->board[add_index_mod(p->pc, *i)];
		((unsigned char *)&ind)[0] = cw->board[add_index_mod(p->pc, *i + 1)];
		ft_printf("%.2x ", cw->board[add_index_mod(p->pc, *i + 0)]);
		ft_printf("%.2x ", cw->board[add_index_mod(p->pc, *i + 1)]);
		v[0] = &cw->board[add_index_mod(p->pc, ind + 0)];
		v[1] = &cw->board[add_index_mod(p->pc, ind + 1)];
		v[2] = p->null[0];
		v[3] = p->null[0];
		*i += 2;
	}
	else if (ft_strcmp(str, "10") == 0)
	{
		if (dir_two == 0)
		{		
			ft_printf("%.2x ", cw->board[add_index_mod(p->pc, *i + 0)]);
			ft_printf("%.2x ", cw->board[add_index_mod(p->pc, *i + 1)]);
			ft_printf("%.2x ", cw->board[add_index_mod(p->pc, *i + 2)]);
			ft_printf("%.2x ", cw->board[add_index_mod(p->pc, *i + 3)]);
			v[3] = &cw->board[add_index_mod(p->pc, *i + 3)];
			v[2] = &cw->board[add_index_mod(p->pc, *i + 2)];
			v[1] = &cw->board[add_index_mod(p->pc, *i + 1)];
			v[0] = &cw->board[add_index_mod(p->pc, *i + 0)];
			*i += 4;
		}
		else
		{		
			ft_printf("%.2x ", cw->board[add_index_mod(p->pc, *i + 0)]);
			ft_printf("%.2x ", cw->board[add_index_mod(p->pc, *i + 1)]);
			v[0] = &cw->board[add_index_mod(p->pc, *i + 0)];
			v[1] = &cw->board[add_index_mod(p->pc, *i + 1)];
			v[2] = p->null[0];
			v[3] = p->null[0];
			*i += 2;
		}
	}
}

void	ocp_parse(t_cw *cw, t_process *p, int *i, t_ocp ocp, int dir_two)
{
	ft_printf("%.2x ", cw->board[add_index_mod(p->pc, 1)]);
	ocp_part(cw, p, i, p->p_one, ocp.one, dir_two);
	ocp_part(cw, p, i, p->p_two, ocp.two, dir_two);
	ocp_part(cw, p, i, p->p_three, ocp.three, dir_two);
}
