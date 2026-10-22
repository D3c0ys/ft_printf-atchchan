/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchchan <atchchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 00:38:24 by atchchan          #+#    #+#             */
/*   Updated: 2026/10/23 00:52:31 by atchchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		write(1, s, 1);
		count++;
		s++;
	}
	return (count);
}
