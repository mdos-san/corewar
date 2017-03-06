/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <ajubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/13 11:12:53 by ajubert           #+#    #+#             */
/*   Updated: 2016/03/05 16:24:56 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int r;
	int i;

	r = 1;
	i = 1;
	if (nb != 0 && power > 0)
	{
		while (i <= power)
		{
			r = r * nb;
			i++;
		}
		return (r);
	}
	else if (nb != 0 && power == 0)
		return (1);
	else if (nb == 0 || power < 0)
		return (0);
	return (0);
}
