/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 13:02:10 by mdos-san          #+#    #+#             */
/*   Updated: 2017/03/06 13:11:53 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_help(void)
{
	ft_putstr("Usage: ./ressources/corewar [-d N] [-n N] ");
	ft_putstr("[-verbose] [-v] [-a] <champion1.cor> <...>\n");
	ft_putstr("\t-d N\t: Dumps memory after N cycles then exits.\n");
	ft_putstr("\t-n N\t: Change next player number to N.\n");
	ft_putstr("\t-verbose: Display verbose output.\n");
	ft_putstr("\t-v\t: Enable ncurse display mode.\n");
	ft_putstr("\t-a\t: Prints output from \"aff\" (Default is to hide it).\n");
	exit(0);
}
