/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:41:14 by ajubert           #+#    #+#             */
/*   Updated: 2016/12/14 13:22:51 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_nb_word(char const *s, char c)
{
	int i;
	int word;
	int nb_word;

	word = 1;
	nb_word = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && word)
		{
			nb_word++;
			word = 0;
		}
		if (s[i] == c)
			word = 1;
		i++;
	}
	return (nb_word);
}

char	**ft_allocation(char const *s, char **str, int nb_word, char c)
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
		while (s[j] == c && s[j])
			j++;
		while (s[j] != c && s[j])
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

char	**ft_split(char const *s, char c, char **str, int nb_word)
{
	int word;
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < nb_word)
	{
		word = 0;
		while (s[j] == c && s[j])
			j++;
		while (s[j] != c && s[j])
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

char	**ft_strsplit(char const *s, char c)
{
	int		nb_word;
	char	**str;

	str = NULL;
	nb_word = ft_nb_word(s, c);
	if (!(str = ft_allocation(s, str, nb_word, c)))
		return (NULL);
	str = ft_split(s, c, str, nb_word);
	return (str);
}
