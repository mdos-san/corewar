/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 12:57:05 by jcao              #+#    #+#             */
/*   Updated: 2016/03/03 14:20:28 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H

# define BUFF_SIZE 32

# include <stdlib.h>
# include "libft.h"

typedef struct	s_var
{
	char	*tmp;
	char	*init;
	char	*buf;
	int		nb_read;
	int		len;
}				t_var;

int				get_next_line(int const fd, char **line);

#endif
