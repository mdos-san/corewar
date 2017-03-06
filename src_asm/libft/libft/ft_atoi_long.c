/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 01:00:09 by ajubert           #+#    #+#             */
/*   Updated: 2016/05/11 15:10:38 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	next_atoi_long(const char *str, int i, int *nombre, long *res)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		*nombre = 0;
		*res = *res * 10 + str[i] - '0';
		i++;
	}
}

long	ft_atoi_long(const char *str)
{
	int		i;
	long	res;
	int		indice;
	int		nombre;

	indice = 1;
	nombre = 1;
	res = 0;
	i = 0;
	while (((str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
					|| str[i] == '\f' || str[i] == '\r')
				|| (str[i] >= '0' && str[i] <= '9')
				|| (str[i] == '-' || str[i] == '+')) && nombre)
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				indice = -1;
			nombre = 0;
			i++;
		}
		next_atoi_long(str, i, &nombre, &res);
		i++;
	}
	return (res * indice);
}
