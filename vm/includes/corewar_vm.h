/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vm.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 13:38:55 by jcao              #+#    #+#             */
/*   Updated: 2016/12/03 13:36:20 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include "libft/includes/libft.h"
# include "op.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef struct		s_war
{
	int		i;
	int		fd;
	int		*buf;
	int		*res;
	char	*str;
	char	**tmp;
}					t_war;

header_t	*check_error(char **av, t_war check, int ac, header_t *head);
header_t	*get_name(t_war name, header_t *head, int ac);
header_t	*size_prog(t_war prog, header_t *head, int ac);
header_t	* get_comment(t_war name, header_t *head, int ac);
header_t	*get_prog(t_war prog, header_t *head, int ac);
int			intro_display(t_war var, header_t *head, int ac);
#endif
