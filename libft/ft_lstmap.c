/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:05:03 by graux             #+#    #+#             */
/*   Updated: 2022/10/11 16:04:26 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*elem;
	t_list	*temp;

	map = NULL;
	while (lst != NULL)
	{
		temp = f(lst->content);
		elem = ft_lstnew(temp);
		if (elem == NULL)
		{
			ft_lstclear(&map, del);
			if (temp != NULL)
				del(temp);
			return (NULL);
		}
		ft_lstadd_back(&map, elem);
		lst = lst->next;
	}
	return (map);
}
