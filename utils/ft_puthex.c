/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchchan <atchchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 19:17:15 by atchchan          #+#    #+#             */
/*   Updated: 2026/10/22 23:57:56 by atchchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf_utils.h"

void	ft_puthex(unsigned long n, int upper)
{
	char	*hexmap;

	if (upper == 1)
		hexmap = "0123456789ABCDEF";
	else
		hexmap = "0123456789abcdef";
	if ((n != 0 && n / 16 == 0) || n == 0)
	{
		ft_putchar_fd(hexmap[n % 16], 1);
		return ;
	}
	ft_puthex(n / 16, upper);
	ft_putchar_fd(hexmap[n % 16], 1);
}
