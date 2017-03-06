/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 21:42:46 by ajubert           #+#    #+#             */
/*   Updated: 2016/04/09 22:03:54 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_plus(t_env2 *env2)
{
	int i;

	i = 0;
	if (env2->test == 0)
		env2->str = ft_strjoin_free(env2->str, "+", env2->str);
	else
	{
		if (!env2->moins)
		{
			while (!(ft_isdigit(env2->str[i + 1])))
				i++;
			env2->str[i] = '+';
		}
		else
		{
			env2->str = ft_strjoin_free(env2->str, "+", env2->str);
			if (env2->test == 1)
				env2->str[ft_strlen(env2->str) - 1] = 0;
		}
	}
}
