/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchchan <atchchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 12:21:05 by atchchan          #+#    #+#             */
/*   Updated: 2026/09/09 19:50:02 by atchchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countdig(int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	writedig(char **p, int n, int index)
{
	if (n / 10 == 0 && n < 0)
		(*p)[0] = '-';
	(*p)[index] = (n % 10) * ((n > 0) - (n < 0)) + '0';
	if (n / 10 != 0)
		writedig(p, n / 10, index - 1);
	return ;
}

char	*ft_itoa(int n)
{
	char	*p;
	int		count;
	int		sign;

	sign = n < 0;
	count = countdig(n);
	p = malloc(count + sign + 1);
	if (!p)
		return (NULL);
	writedig(&p, n, count - 1 + sign);
	p[count + sign] = '\0';
	return (p);
}
