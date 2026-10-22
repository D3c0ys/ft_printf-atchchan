/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchchan <atchchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 23:12:11 by atchchan          #+#    #+#             */
/*   Updated: 2026/10/23 00:52:28 by atchchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int	ft_putunbr(unsigned int n)
{
	char	num;
	int		count;

	count = 0;
	num = n % 10 + '0';
	if ((n != 0 && n / 10 == 0) || n == 0)
	{
		write(1, &num, 1);
		return (1);
	}
	count += ft_putunbr(n / 10);
	write(1, &num, 1);
	count++;
	return (count);
}
