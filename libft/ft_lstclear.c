/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchchan <atchchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 00:24:04 by atchchan          #+#    #+#             */
/*   Updated: 2026/09/10 16:47:00 by atchchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Delete whole list

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp_node;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp_node = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp_node;
	}
	*lst = NULL;
}
