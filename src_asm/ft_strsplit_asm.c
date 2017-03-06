/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_asm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 11:59:50 by ajubert           #+#    #+#             */
/*   Updated: 2017/02/25 13:38:45 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_asm.h"

static int		ft_nb_word(char const *s)
{
	int i;
	int word;
	int nb_word;

	word = 1;
	nb_word = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == ';' || s[i] == '#')
			break ;
		if (s[i] != ' ' && s[i] != '\t' && word)
		{
			nb_word++;
			word = 0;
		}
		if (s[i] == ' ' || s[i] == '\t')
			word = 1;
		i++;
	}
	return (nb_word);
}

static char		**ft_allocation(char const *s, char **str, int nb_word)
{
	int word;
	int i;
	int j;

	if (!(str = (char **)malloc(sizeof(char *) * (nb_word + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < nb_word + 1)
	{
		word = 0;
		while ((s[j] == ' ' || s[j] == '\t') && s[j])
			j++;
		while (s[j] != ' ' && s[j] != '\t' && s[j])
		{
			word++;
			j++;
		}
		if (!(str[i] = (char *)malloc(sizeof(char) * (word + 1))))
			return (NULL);
		i++;
	}
	if (str == NULL)
		return (NULL);
	return (str);
}

static char		**ft_split(char const *s, char **str, int nb_word)
{
	int word;
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < nb_word)
	{
		word = 0;
		while ((s[j] == ' ' || s[j] == '\t') && s[j])
			j++;
		while (s[j] != ' ' && s[j] != '\t' && s[j])
		{
			str[i][word] = s[j];
			j++;
			word++;
		}
		str[i][word] = '\0';
		i++;
	}
	str[i][0] = '\0';
	return (str);
}

char			**ft_strsplit_asm(char const *s, int *size)
{
	char	**str;

	str = NULL;
	*size = ft_nb_word(s);
	if (!(str = ft_allocation(s, str, *size)))
		return (NULL);
	str = ft_split(s, str, *size);
	return (str);
}
