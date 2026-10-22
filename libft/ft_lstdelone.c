/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchchan <atchchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 00:17:39 by atchchan          #+#    #+#             */
/*   Updated: 2026/09/10 16:50:04 by atchchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Delete specific node (If not last, the chain is cutted)

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
