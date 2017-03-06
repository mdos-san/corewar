/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_or_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 10:54:24 by ajubert           #+#    #+#             */
/*   Updated: 2017/03/02 15:38:58 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_asm.h"

char	*first_word(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	j = 0;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str[i + j] && (!ft_strchr(" \t", str[i + j])))
		j++;
	if (j == 0)
		return (NULL);
	if (!(tmp = ft_strsub(str, i, j)))
		exit(0);
	return (tmp);
}

char	*second_word(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	j = 0;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str[i + j] && (!ft_strchr(" \t", str[i + j])))
		i++;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str[i + j] && (!ft_strchr(" \t", str[i + j])))
		j++;
	if (j == 0)
		return (NULL);
	if (!(tmp = ft_strsub(str, i, j)))
		exit(0);
	return (tmp);
}

int		calc(char **word, char **word2, t_e *e)
{
	if (e->op == 0 && ft_strcmp(word[0], e->liste_op[e->i]) == 0)
	{
		free_line(word);
		free_line(word2);
		return (1);
	}
	if (e->op == 3 && word2[0] && ft_strcmp(e->liste_op[e->i], word2[0]) == 0)
	{
		free_line(word);
		free_line(word2);
		return (2);
	}
	return (0);
}

void	free_word(char **word, char **word2)
{
	free_line(word);
	free_line(word2);
}

int		op_or_ft(char *str, t_e *e)
{
	char	*word;
	char	*word2;
	int		r;

	e->op = 0;
	word = first_word(str);
	word2 = second_word(str);
	if (word == NULL)
		return (0);
	e->i = -1;
	if (ft_strchr(word, ':'))
		e->op = 3;
	while (++e->i < NB_OP)
	{
		r = calc(&word, &word2, e);
		if (r == 1 || r == 2)
			return (r);
	}
	if (e->op == 3)
	{
		free_word(&word, &word2);
		return (3);
	}
	free_word(&word, &word2);
	return (0);
}
