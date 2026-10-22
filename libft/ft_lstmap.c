/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchchan <atchchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 16:33:49 by atchchan          #+#    #+#             */
/*   Updated: 2026/09/10 17:48:18 by atchchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*content;
	t_list	*node;
	t_list	*new_node;

	if (!lst || !(*f))
		return (NULL);
	node = NULL;
	while (lst)
	{
		content = (*f)(lst->content);
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			if (del && content)
				del(content);
			ft_lstclear(&node, del);
			return (NULL);
		}
		ft_lstadd_back(&node, new_node);
		lst = lst->next;
	}
	return (node);
}
