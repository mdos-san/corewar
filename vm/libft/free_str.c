/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 16:18:36 by jcao              #+#    #+#             */
/*   Updated: 2016/04/11 12:02:41 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_str(char *str, char *str1, char *str2, char *str3)
{
	if (str != NULL)
		free(str);
	if (str1 != NULL)
		free(str1);
	if (str2 != NULL)
		free(str2);
	if (str3 != NULL)
		free(str3);
}
