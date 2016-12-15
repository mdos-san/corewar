/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 12:26:33 by jcao              #+#    #+#             */
/*   Updated: 2015/12/09 17:24:32 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*res;
	int		i;
	int		tmp;
	int		k;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	tmp = ft_strlen(s) - 1;
	res = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (res == NULL)
		return (NULL);
	while (s[tmp] == 32 || s[tmp] == '\n' || s[tmp] == '\t')
		tmp--;
	while (s[i] == 32 || s[i] == '\n' || s[i] == '\t')
		i++;
	if (tmp >= i)
	{
		while (i <= tmp)
			res[k++] = s[i++];
	}
	res[k] = '\0';
	return (res);
}
