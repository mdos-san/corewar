/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:38:11 by jcao              #+#    #+#             */
/*   Updated: 2017/02/11 15:32:47 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_asm.h"

static int	wrong_type(t_asm *var)
{
	ft_printf("Invalid parameter %d type ", var->type);
	if (var->type_code == 1)
		ft_printf("%s for instruction %s\n", DIRECT, var->instruc);
	else if (var->type_code == 2)
		ft_printf("%s for instruction %s\n", INDIRECT, var->instruc);
	if (var->type_code == 3)
		ft_printf("%s for instruction %s\n", REGISTER, var->instruc);
	return (-5);
}

static int	wrong_paramters(t_asm *var)
{
	ft_printf("Invalid parameter count for instruction %s\n", var->instruc);
	return (-4);
}

static int	wrong_list(t_asm *var)
{
	if (var->tmp != NULL)
		free(var->tmp);
	var->tmp = next_str_error(var);
	ft_printf("No such label %s while attempting to dereference", &var->tmp[2]);
	ft_printf(" token [TOKEN][%03d:%03d] ", var->r, var->l);
	ft_printf("DIRECT_LABEL \"%s\"\n", var->tmp);
	return (-3);
}

static int	wrong_reg(void)
{
	ft_printf("Corewar cannot have more than %d register", REG_NUMBER);
	return (-2);
}

int			print_errors(int num, t_asm *var)
{
	if (num == -5)
		return (wrong_type(var));
	else if (num == -4)
		return (wrong_paramters(var));
	else if (num == -3)
		return (wrong_list(var));
	else if (num == -2)
		return (wrong_reg());
	else if (num == -1)
		return (print_syntax(var));
	return (num);
}
