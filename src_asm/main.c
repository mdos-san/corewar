/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:30:12 by jcao              #+#    #+#             */
/*   Updated: 2017/03/06 14:49:36 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_asm.h"

static t_asm	*var_init(t_asm *var)
{
	var->fd = 0;
	var->l = 1;
	var->r = 1;
	var->i = 0;
	var->k = 0;
	var->ll = 0;
	var->check_n = 0;
	var->name = 0;
	var->comment = 0;
	var->init = 0;
	var->type = 0;
	var->type_code = 0;
	var->stock = NULL;
	var->list = NULL;
	var->tmp = NULL;
	var->param = NULL;
	var->instruc = NULL;
	var->error = NULL;
	var->first = 0;
	var->iname = 0;
	var->icomment = 0;
	var->final = NULL;
	var->tmp2 = NULL;
	return (var);
}

static int		error_open(int ac, char **av)
{
	ft_printf("Can't read source file %s\n", av[ac - 1]);
	return (-1);
}

static int		error_champ(t_asm *var)
{
	ft_printf("Champion ");
	if (var->iname > PROG_NAME_LENGTH)
		ft_printf("name too long (Max length %d)\n", PROG_NAME_LENGTH);
	else if (var->icomment > COMMENT_LENGTH)
		ft_printf("comment too long (Max length %d)\n", COMMENT_LENGTH);
	return (-1);
}

static int		check_error(t_asm *var)
{
	if (var->stock == NULL)
		return (print_syntax(var));
	var->list = create_list(var);
	if (lexical_error(var) != 1)
		return (print_lexical(var));
	if (syntax_error(var) != 1)
		return (print_syntax(var));
	if (var->iname > PROG_NAME_LENGTH || var->icomment > COMMENT_LENGTH)
		return (error_champ(var));
	return (-10);
}

int				main(int ac, char **av)
{
	t_asm	*var;
	int		res;

	var = (t_asm *)malloc(sizeof(t_asm) * 1);
	var = var_init(var);
	var->fd = open(av[ac - 1], O_RDONLY);
	if (ac < 2)
		return (write(1, "Usage: ./asm <sourcefile.s>\n", 28));
	if (var->fd < 0)
		return (error_open(ac, av));
	var->stock = stock_read(var);
	if (check_error(var) != -10)
		return (-1);
	res = seek_instruc(var, av);
	if (res < 0)
	{
		print_errors(res, var);
		return (-1);
	}
	var->final = extension(av[1]);
	if (write_file(ac, av) != 0)
		return (-1);
	ft_printf("Writing output program to %s\n", var->final);
	return (1);
}
