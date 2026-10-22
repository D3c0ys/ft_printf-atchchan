/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchchan <atchchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 19:10:23 by atchchan          #+#    #+#             */
/*   Updated: 2026/10/22 23:31:55 by atchchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf_utils.h"

void	ft_putptr(void *p)
{
	unsigned long	q;

	if (p == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		return ;
	}
	q = (unsigned long)p;
	ft_putstr_fd("0x", 1);
	ft_puthex(q, 0);
}
