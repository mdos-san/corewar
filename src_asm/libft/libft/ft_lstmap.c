/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 11:55:46 by ajubert           #+#    #+#             */
/*   Updated: 2015/12/15 11:55:50 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*chain;
	t_list	*tmp;
	t_list	*tmp2;

	chain = ft_lstnew_cpy(lst->content, lst->content_size);
	chain = f(chain);
	tmp = chain;
	tmp2 = NULL;
	while (lst)
	{
		lst = lst->next;
		if (!lst)
			return (chain);
		tmp2 = ft_lstnew_cpy(lst->content, lst->content_size);
		tmp2 = f(tmp2);
		tmp->next = tmp2;
		tmp = tmp->next;
	}
	return (chain);
}
