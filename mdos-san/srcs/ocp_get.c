#include "corewar.h"

char	*get_bin(long long nbr, unsigned int base)
{
	int			i;
	long long	mod;
	char		buf[1024];
	long long	neg;

	i = 0;
	ft_bzero(buf, 1024);
	if (nbr == 0)
		return (ft_strdup("0"));
	neg = (nbr < 0) ? -1 : 1;
	while (nbr != 0)
	{
		mod = nbr % base;
		if (mod <= 9)
			buf[1022 - i] = mod * neg + 48;
		else
		{
			mod -= 10;
			buf[1022 - i] = mod * neg + 97;
		}
		nbr /= base;
		++i;
	}
	while (i < 8)
	{
		buf[1022 - i] = '0';
		++i;
	}
	(neg == -1) ? buf[1022 - i] = '-' : 0;
	return (ft_strdup(buf + 1022 - i + 1 - ((neg == -1) ? 1 : 0)));
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