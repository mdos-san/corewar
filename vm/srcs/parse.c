/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 08:20:57 by mdos-san          #+#    #+#             */
/*   Updated: 2017/03/06 16:18:18 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	get_value(t_cw *cw, int *i, int *n, char *str)
{
	if (*i + 1 < cw->ac)
		*n = ft_atoi(cw->av[*i + 1]);
	else
		error(cw, str);
	++*i;
}

static int	travel_av(t_cw *cw, int *nb_player, int *nb, int i)
{
	if (i >= cw->ac)
		return (0);
	if (ft_strcmp(cw->av[i], "-dump") == 0)
		get_value(cw, &i, &cw->f_dump, "-dump value is missing.");
	else if (ft_strcmp(cw->av[i], "-d") == 0)
		get_value(cw, &i, &cw->f_dump, "-d value is missing.");
	else if (ft_strcmp(cw->av[i], "-n") == 0 && *nb_player < 4)
		get_value(cw, &i, nb + *nb_player, "-n value is missing.");
	else if (ft_strcmp(cw->av[i], "-v") == 0)
		cw->f_v = 1;
	else if (ft_strcmp(cw->av[i], "-verbose") == 0)
		cw->f_verbose = 1;
	else if (cw->av[i][0] != '-' && *nb_player < 4)
	{
		cw->champs[*nb_player].path = cw->av[i];
		cw->fd = open(cw->av[i], O_RDONLY);
		if (cw->fd == -1)
			error(cw, cw->av[i]);
		if (close(cw->fd) == -1)
			error(cw, cw->av[i]);
		++*nb_player;
	}
	else if (cw->av[i][0] != '-')
		error(cw, "Too many player.");
	return (travel_av(cw, nb_player, nb, ++i));
}

static int	parse_get_flag(t_cw *cw, int *nb)
{
	int		nb_player;

	nb_player = 0;
	travel_av(cw, &nb_player, nb, 1);
	return (nb_player);
}

static void	wait_init(t_process *p)
{
	if (p != NULL)
	{
		p->is_waiting = 0;
		wait_init(p->next);
	}
}

void		cw_parse(t_cw *cw)
{
	int		nb_player;
	int		i;
	int		nb[4];

	nb[0] = -1;
	nb[1] = -2;
	nb[2] = -3;
	nb[3] = -4;
	nb_player = parse_get_flag(cw, nb);
	if (nb_player > 4 || nb_player < 1)
		error(cw, "Bad number of player.");
	i = 0;
	ft_printf("Introducing contestants...\n");
	while (i < nb_player)
	{
		ft_printf("* Player %d, ", i + 1);
		bytecode_read(cw, cw->champs[i].path,
		(MEM_SIZE / nb_player) * i, i + 1);
		if (!process_new(&cw->process, nb[i], MEM_SIZE / nb_player * i, i + 1))
			cw_exit(cw, 1, "Malloc fail, can't create a new process.");
		ft_printf("\n");
		cw->champs[i].number = nb[i];
		++i;
	}
	wait_init(cw->process);
}
