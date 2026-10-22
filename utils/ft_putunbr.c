/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchchan <atchchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 23:12:11 by atchchan          #+#    #+#             */
/*   Updated: 2026/10/22 23:57:52 by atchchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf_utils.h"

void	ft_putunbr(unsigned int n)
{
	char	num;

	num = n % 10 + '0';
	if ((n != 0 && n / 10 == 0) || n == 0)
	{
		write(1, &num, 1);
		return ;
	}
	ft_putunbr(n / 10);
	write(1, &num, 1);
}
