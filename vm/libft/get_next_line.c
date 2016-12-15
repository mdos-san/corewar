/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 13:01:04 by jcao              #+#    #+#             */
/*   Updated: 2016/03/03 14:21:03 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

static char	*stock_linenl(char **line, char *stock, t_var var, int len)
{
	if (ft_strchr(stock, '\n') != NULL)
	{
		*line = ft_strsub(stock, 0, ft_strchr(stock, '\n') - stock);
		var.init = ft_strchr(stock, '\n') + 1;
		var.tmp = ft_strnew(ft_strlen(var.init) + 1);
		var.tmp = ft_strcpy(var.tmp, var.init);
		free(stock);
		stock = ft_strnew(ft_strlen(var.tmp));
		stock = ft_strcpy(stock, var.tmp);
		free(var.tmp);
	}
	else if (ft_strchr(stock, '\0') != NULL)
	{
		*line = ft_strsub(stock, 0, ft_strchr(stock, '\0') - stock);
		free(stock);
		stock = ft_strnew(1);
	}
	else
	{
		*line = ft_strsub(stock, 0, len);
		free(stock);
		stock = ft_strnew(1);
	}
	return (stock);
}

static char	*loop_read(t_var var, char *stock, int const fd, char **line)
{
	var.tmp = ft_strchr(stock, '\n');
	while (var.tmp == NULL && var.nb_read > 0)
	{
		var.buf = ft_strnew(BUFF_SIZE);
		var.nb_read = read(fd, var.buf, BUFF_SIZE);
		var.init = ft_strjoin(stock, var.buf);
		free(stock);
		free(var.buf);
		stock = ft_strnew(ft_strlen(var.init));
		stock = ft_strcpy(stock, var.init);
		free(var.init);
		var.tmp = ft_strchr(stock, '\n');
	}
	stock = stock_linenl(line, stock, var, var.len);
	return (stock);
}

static char	*init_stock(t_var var, char *stock, char *buf)
{
	if (stock == NULL)
		stock = ft_strnew(BUFF_SIZE + 1);
	var.init = ft_strjoin(stock, buf);
	free(stock);
	free(buf);
	stock = ft_strnew(ft_strlen(var.init) + 1);
	stock = ft_strcpy(stock, var.init);
	free(var.init);
	return (stock);
}

int			get_next_line(int const fd, char **line)
{
	static char *stock[256];
	t_var		var;

	if (line == NULL)
		return (-1);
	var.buf = ft_strnew(BUFF_SIZE + 1);
	var.nb_read = read(fd, var.buf, BUFF_SIZE);
	if (var.nb_read == -1 || BUFF_SIZE <= 0 || fd > 256)
		return (-1);
	stock[fd] = init_stock(var, stock[fd], var.buf);
	var.len = ft_strlen(stock[fd]);
	if (ft_strchr(stock[fd], '\n') != NULL)
		stock[fd] = stock_linenl(line, stock[fd], var, var.len);
	else if (var.nb_read != 0)
		stock[fd] = loop_read(var, stock[fd], fd, line);
	else if (var.nb_read == 0 && var.len != 0)
		stock[fd] = stock_linenl(line, stock[fd], var, var.len);
	else
	{
		*line = "\0";
		return (0);
	}
	return (1);
}
