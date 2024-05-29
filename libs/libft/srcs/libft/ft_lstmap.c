/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturiot <eturiot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:12:14 by eturiot           #+#    #+#             */
/*   Updated: 2022/11/28 13:08:31 by eturiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*begin_lst;
	t_list	*lst_new;
	t_list	*lst_temp;

	if (lst && f)
	{
		lst_new = ft_lstnew(f(lst->content));
		if (!lst_new)
			return (NULL);
		begin_lst = lst_new;
		lst = lst->next;
	}
	while (lst && f)
	{
		lst_temp = ft_lstnew(f(lst->content));
		if (!lst_temp && del)
		{
			ft_lstclear(&begin_lst, del);
			return (NULL);
		}
		lst_new->next = lst_temp;
		lst_new = lst_new->next;
		lst = lst->next;
	}
	return (begin_lst);
}
