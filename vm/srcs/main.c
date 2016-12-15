/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 13:34:53 by jcao              #+#    #+#             */
/*   Updated: 2016/12/05 11:47:52 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

static int corewar_help()
{
	ft_printf("Usage: ./corewar [-dump nbr_cycles] [[-n number] champion1.cor] ");
	ft_printf("...\nAide Corewar:\n\n-dump nbr_cycles : Au bout de nbr_cycles d");
	ft_printf("'exécution, dump la mémoire sur la sortie standard, puis quitte ");
	ft_printf("la partie.\n-n number: Fixe le numéro du prochain joueur. Si abs");
	ft_printf("ent, le joueur aura le prochain numéro dans l'ordre des paramètr");
	ft_printf("es.\n\nCe corewar ne supportera pas plus de 4 champions.\n");
	return (0);
}

static t_war var_init()
{
	t_war init;
	
	init.i = 1;
	init.fd = 0;
	init.buf = NULL;
	init.tmp = NULL;
	init.str = NULL;
	init.res = NULL;
	return (init);
}

static header_t head_init(header_t *head, int i)
{
	head[i].magic = 0;
	head[i].prog_size = 0;
	head[i].prog_exec = NULL;
	return (head[i]);
}

int	main(int ac, char **av)
{
	t_war var;
	header_t	*head;

	var = var_init();
	if (!(head = (header_t *)malloc(sizeof(header_t) * ac)))
		return (-1);
	if (ac == 1)
		return corewar_help();
	else if (ac > MAX_PLAYERS + 1)
		return (write(1, "Trop de champions\n",18));
	else
	{
		while (ac > var.i)
		{
			head[var.i] = head_init(head, var.i);
			head = check_error(av, var, var.i, head);
			if (head == NULL)
				return (-1);
			var.i++;
		}
		intro_display(var, head, ac);
	}
	//while (1);
	return (0);
}
