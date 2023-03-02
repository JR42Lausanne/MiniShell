/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_as_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:09:18 by graux             #+#    #+#             */
/*   Updated: 2023/03/01 16:47:33 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tokenizer.h"

t_token	**tokenizer_as_array(t_tokenizer *toker)
{
	t_token	**array;
	t_list	*lst;
	int		i;
	int		len;

	len = ft_lstsize(toker->tokens);
	array = malloc((len + 1) * sizeof(t_token *));
	if (!array)
		return (NULL);
	lst = toker->tokens;
	i = 0;
	while (lst)
	{
		array[i++] = lst->content;
		lst = lst->next;
	}
	array[i] = NULL;
	return (array);
}
