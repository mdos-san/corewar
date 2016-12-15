/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_prog.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 13:29:03 by jcao              #+#    #+#             */
/*   Updated: 2016/11/27 13:31:08 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

int		stock_prog(t_war prog)
{
	int		i;
	char	*octet1;
	char	*octet2;
	char	*tmp;
	
	tmp = NULL;
	octet1 = NULL;
	octet2 = NULL;
	i = 0;
	octet1 = ft_itoa_base(prog.buf[0], 2);
	free(prog.buf);
	if (read(prog.fd, prog.buf, 1) > 0)
	{
		octet2 = ft_itoa_base(prog.buf[0], 2);
		tmp = ft_strjoin(octet1, octet2);
		i = ft_atoi_base(tmp, 2);
//		ft_putnbr(i);
	}
	else
		return (-1);
	free(octet1);
	free(octet2);
	free(tmp);
	return (get_comment(prog));
}
