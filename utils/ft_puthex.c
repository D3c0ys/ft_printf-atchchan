/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchchan <atchchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 19:17:15 by atchchan          #+#    #+#             */
/*   Updated: 2026/10/23 00:51:05 by atchchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int	ft_puthex(unsigned long n, int upper)
{
	char	*hexmap;
	int		count;

	count = 0;
	if (upper == 1)
		hexmap = "0123456789ABCDEF";
	else
		hexmap = "0123456789abcdef";
	if ((n != 0 && n / 16 == 0) || n == 0)
	{
		write(1, hexmap + n % 16, 1);
		return (1);
	}
	count += ft_puthex(n / 16, upper);
	write(1, hexmap + n % 16, 1);
	count++;
	return (count);
}
