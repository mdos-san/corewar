/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_asm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 13:07:35 by ajubert           #+#    #+#             */
/*   Updated: 2017/03/02 15:45:45 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_asm.h"

void	print_header(t_e *e)
{
	int i;

	i = -1;
	while (++i < 4)
		ft_printf_fd(e->fd1, "%c", e->header.magic[i]);
	ft_putstr_size_fd(e->fd1, e->header.prog_name, PROG_NAME_LENGTH);
	if (!(e->header.size = (unsigned char*)convert(e->header.prog_size, 8)))
		exit(0);
	i = -1;
	while (++i < 8)
		ft_printf_fd(e->fd1, "%c", e->header.size[i]);
	ft_putstr_size_fd(e->fd1, e->header.comment, COMMENT_LENGTH);
	i = -1;
	while (++i < 4)
		ft_printf_fd(e->fd1, "%c", 0);
}

int		write_file(int argc, char **argv)
{
	t_e			e;
	int			i;

	ft_bzero(&e, sizeof(t_e));
	e.fd = open(argv[argc - 1], O_RDONLY);
	recup_file(&e);
	i = 0;
	while (argv[argc - 1][i] != '.')
		i++;
	if (!(e.str = ft_strsub(argv[argc - 1], 0, i)))
		return (0);
	e.str = ft_strjoin_free(e.str, e.str, ".cor");
	e.fd1 = open(e.str, O_CREAT | O_RDWR | O_APPEND | O_TRUNC, 0640);
	if (e.fd1 == -1)
		return (ft_printf("Error to create file\n"));
	init_liste_op(&e);
	e.nb_instruct = count_nb_instruct(e.liste, &e);
	if (!(e.tab = (t_op_ft *)malloc(sizeof(t_op_ft) * e.nb_instruct)))
		return (0);
	create_tab(&e);
	create_header(&e);
	print_header(&e);
	print_prog(&e);
	ft_free_all(&e);
	return (0);
}
