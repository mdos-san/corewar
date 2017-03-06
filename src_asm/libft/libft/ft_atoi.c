/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:28:09 by ajubert           #+#    #+#             */
/*   Updated: 2015/11/30 08:34:50 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	next_atoi(const char *str, int i, int *nombre, int *res)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		*nombre = 0;
		*res = *res * 10 + str[i] - '0';
		i++;
	}
}

int		ft_atoi(const char *str)
{
	int i;
	int res;
	int indice;
	int nombre;

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
		next_atoi(str, i, &nombre, &res);
		i++;
	}
	return (res * indice);
}
