/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 17:37:25 by jcao              #+#    #+#             */
/*   Updated: 2016/12/05 11:40:14 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

static char		*free_join(char *str, char *tmp)
{
	char *stock;

	stock = str;
	str = ft_strjoin(stock, tmp);
	free(stock);
	return (str);
}

void	error_magic(char *fil)
{
	ft_printf("Error : File %s has an invalid header", fil); // sortie d'erreur
	exit();
}

void	check_exec(t_war *var, char *fil)
{
	int i;
	char *tmp;
	char c;
	char *str;

	str = NULL;
	i = 0;
	if ((var->fd = open(fil, O_RDONLY)) < 1) // verif fd 0
	{
		write(1, "Can't read source file ", 23);
		strerror(fil);
	}
	while (i < 4)
	{
		read(var->fd, &c, 1)
		tmp = ft_itoa_base(c, 2);
		str = free_join(str, tmp); //verif first join quand str = NULL
		free(tmp);
		i++;
	}
	if (ft_atoi(str) != COREWAR_EXEC_MAGIC)
		error_magic(fil);
	free(str);
}
