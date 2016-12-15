/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 15:10:59 by jcao              #+#    #+#             */
/*   Updated: 2015/12/10 15:09:51 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *mem_next;

	if (alst && del)
	{
		while (*alst != NULL)
		{
			mem_next = (*alst)->next;
			del((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = mem_next;
		}
	}
	ft_memdel((void **)alst);
}
