/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchchan <atchchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 00:32:12 by atchchan          #+#    #+#             */
/*   Updated: 2026/10/23 00:52:41 by atchchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int	ft_putnbr(int n)
{
	char	c;
	int		count;

	count = 0;
	if (n / 10 == 0 && n < 0)
		count += write(1, "-", 1);
	c = (n % 10) * ((n > 0) - (n < 0)) + '0';
	if (n / 10 != 0)
		count += ft_putnbr(n / 10);
	count += write(1, &c, 1);
	return (count);
}
