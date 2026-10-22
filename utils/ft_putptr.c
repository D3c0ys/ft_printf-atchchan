/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchchan <atchchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 19:10:23 by atchchan          #+#    #+#             */
/*   Updated: 2026/10/23 00:52:55 by atchchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int	ft_putptr(void *p)
{
	unsigned long	q;
	int				count;

	count = 0;
	if (p == NULL)
	{
		count += write(1, "(nil)", 5);
		return (count);
	}
	q = (unsigned long)p;
	count += write(1, "0x", 2) + ft_puthex(q, 0);
	return (count);
}
