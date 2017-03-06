/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 15:30:41 by jcao              #+#    #+#             */
/*   Updated: 2017/02/11 15:56:44 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_asm.h"

static int		print_direct(t_asm *var)
{
	char *tmp;

	tmp = NULL;
	ft_printf("Syntax error at token [TOKEN][%03d:%03d] ", var->r, var->l);
	if (var->stock[var->i + 1] == LABEL_CHAR)
	{
		var->i = var->i + 2;
		tmp = print_label_chars(var);
		ft_printf("DIRECT_LABEL \"%c%c%s\"\n", DIRECT_CHAR, LABEL_CHAR, tmp);
	}
	else
	{
		var->i++;
		tmp = print_label_chars(var);
		ft_printf("DIRECT \"%c%s\"\n", DIRECT_CHAR, tmp);
	}
	return (-1);
}

static int		instruc_error(t_asm *var)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = print_label_chars(var);
	while (tmp[i] != '\0')
		i++;
	i--;
	if (tmp[i] == LABEL_CHAR)
	{
		ft_printf("Syntax error at token [TOKEN][%03d:%03d] ", var->r, var->l);
		ft_printf("LABEL \"%s\"\n", tmp);
	}
	else
	{
		ft_printf("Invalid instruction at token ");
		ft_printf("[TOKEN][%03d:%03d] ", var->r, var->l);
		ft_printf("INSTRUCTION \"%s\"\n", tmp);
	}
	return (-1);
}

static int		print_syntax2(t_asm *var)
{
	if (ft_strncmp(&var->stock[var->i], NAME_CMD_STRING,
	ft_strlen(NAME_CMD_STRING)) == 0)
	{
		ft_printf("Syntax error at token [TOKEN][%03d:%03d] ", var->r, var->l);
		return (ft_printf("COMMAND_NAME \"%s\"\n", NAME_CMD_STRING));
	}
	else if (ft_strncmp(&var->stock[var->i], COMMENT_CMD_STRING,
	ft_strlen(COMMENT_CMD_STRING)) == 0)
	{
		ft_printf("Syntax error at token [TOKEN][%03d:%03d] ", var->r, var->l);
		return (ft_printf("COMMAND_COMMENT \"%s\"\n", COMMENT_CMD_STRING));
	}
	else if (var->stock[var->i] == SEPARATOR_CHAR)
	{
		ft_printf("Syntax error at token [TOKEN][%03d:%03d] ", var->r, var->l);
		return (ft_printf("SEPARATOR \"%c\"\n", SEPARATOR_CHAR));
	}
	else if (var->stock[var->i] == DIRECT_CHAR)
		return (print_direct(var));
	else
		return (instruc_error(var));
	return (-1);
}

int				print_syntax(t_asm *var)
{
	if (var->stock == NULL || var->stock[var->i] == '\0')
	{
		ft_printf("Syntax error at token [TOKEN][%03d:%03d] ", var->r, var->l);
		return (ft_printf("END \"(null)\"\n"));
	}
	while (ft_isspace(var->stock[var->i]) == 1)
	{
		if (var->stock[var->i] == '\n')
		{
			ft_printf("Syntax error ");
			ft_printf("at token [TOKEN][%03d:%03d] ", var->r, var->l);
			ft_printf("ENDLINE\n");
			return (-1);
		}
		var->l++;
		var->i++;
	}
	if (var->stock[var->i] == '\0')
	{
		ft_printf("Syntax error at token [TOKEN][%03d:%03d] ", var->r, var->l);
		return (ft_printf("END \"(null)\"\n"));
	}
	else
		return (print_syntax2(var));
}
