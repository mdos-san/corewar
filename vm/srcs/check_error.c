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

static t_war	malloc_var(t_war check)
{
	check.str = ft_strnew(2);
	check.res = (int *)malloc(sizeof(int) * 5);
	check.buf = (int *)malloc(sizeof(int) * 2);
	check.tmp = (char **)malloc(sizeof(char *) * 5);
	return (check);
}

static char		*strjoin(char *str, char *tmp)
{
	char *stock;

	stock = ft_strdup(str);
	free(str);
	str = ft_strjoin(stock, tmp);
	free(stock);
	return (str);
}

static header_t *error_magic(char **av, int ac)
{
	ft_printf("Error : File %s has an invalid header", av[ac]);
	return (NULL);
}

header_t		*check_error(char **av, t_war check, int ac, header_t *head)
{
	int i;

	i = 0;
	check = malloc_var(check);
	check.fd = open(av[ac], O_RDONLY);
	while ((read(check.fd, check.buf, 1) > 0) && (i < 4))
	{
		check.res[i] = check.buf[0];
		i++;
	}
	check.res[4] = 0;
	i = 0;
	while (i < 4)
	{
		check.tmp[i] = ft_itoa_base(check.res[i], 2);
		check.str = strjoin(check.str, check.tmp[i]);
		ft_strdel(&check.tmp[i]);
		i++;
	}
	head[ac].magic = ft_atoi_base(check.str, 2);
	free(check.res);
	free(check.tmp);
	ft_strdel(&check.str);
	if (head[ac].magic != COREWAR_EXEC_MAGIC)
		return (error_magic(av, ac));
	else
		return (get_name(check, head, ac));
}
