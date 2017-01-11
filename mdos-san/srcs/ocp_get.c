#include "corewar.h"

char	*get_bin(long long nbr, unsigned int base)
{
	int			i;
	long long	mod;
	long long	neg;
	char		buf[9];

	i = 0;
	ft_bzero(buf, 9);
	if (nbr == 0)
		return (ft_strdup("0"));
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
	(neg == -1) ? buf[7 - i] = '-' : 0;
	return (ft_strdup(buf + 7 - i + 1 - ((neg == -1) ? 1 : 0)));
}

t_ocp	ocp_get(unsigned char ocp)
{
	char	*str;
	t_ocp	st;

	str = get_bin(ocp, 2);
	st.one[0] = str[0];
	st.one[1] = str[1];
	st.one[2] = 0;
	st.two[0] = str[2];
	st.two[1] = str[3];
	st.two[2] = 0;
	st.three[0] = str[4];
	st.three[1] = str[5];
	st.three[2] = 0;
	free(str);
	return (st);
}

/*
**	ocp_parse permet de recuperer les bons parametre en fonction de t_ocp ocp
**	les parametres sont initialise dans des int passé en parametre
**	La fonction est juste faite pour sti, des amelioration sont a faire pour quelle soit utilisable dans toute les fonctions
*/

static	void	ocp_part(t_cw *cw, t_process *p, int *i,  int **one, char *str, int dir_two)
{
	if (ft_strcmp(str, "01") == 0)
	{
		if (1 <= cw->board[p->pc + *i] && cw->board[p->pc + *i] <= 16)
			*one = p->r + (cw->board[p->pc + *i]) - 1;
		++*i;
	}
	else if (ft_strcmp(str, "11") == 0 || dir_two == 1)// || ft_strcmp(ocp.one, "11") == 0)
	{
		((unsigned char *)*one)[1] = cw->board[p->pc + *i];
		((unsigned char *)*one)[0] = cw->board[p->pc + *i + 1];
		*i += 2;
	}
	else if (ft_strcmp(str, "10") == 0)
	{
		((unsigned char *)*one)[3] = cw->board[p->pc + *i];
		((unsigned char *)*one)[2] = cw->board[p->pc + *i + 1];
		((unsigned char *)*one)[1] = cw->board[p->pc + *i + 2];
		((unsigned char *)*one)[0] = cw->board[p->pc + *i + 3];
		*i += 4;
	}
}

void	ocp_parse(t_cw *cw, t_process *p, int *i, t_ocp ocp, int **one, int **two, int **three, int dir_two)
{
	**one = 0;
	**two = 0;
	**three = 0;
	ocp_part(cw, p, i, one, ocp.one, dir_two);
	ocp_part(cw, p, i, two, ocp.two, dir_two);
	ocp_part(cw, p, i, three, ocp.three, dir_two);
}
