/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchchan <atchchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 23:48:43 by atchchan          #+#    #+#             */
/*   Updated: 2026/10/23 00:54:01 by atchchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putformat(char c, va_list args)
{
	int	count;
	int	num;

	count = 0;
	if (c == 'c')
	{
		num = va_arg(args, int);
		count += write(1, &num, 1);
	}
	else if (c == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		count += ft_putptr(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		count += ft_putunbr((unsigned int)va_arg(args, int));
	else if (c == 'x')
		count += ft_puthex(va_arg(args, unsigned int), 0);
	else if (c == 'X')
		count += ft_puthex(va_arg(args, unsigned int), 1);
	else if (c == '%')
		count += write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*p;
	int		count;

	count = 0;
	p = (char *)format;
	va_start(args, format);
	while (*p)
	{
		if (*p == '%' && *(p + 1))
			count += putformat(*(++p), args);
		else
		{
			write(1, p, 1);
			count++;
		}
		p++;
	}
	va_end(args);
	return (count);
}

// int main(void)
//{
//	ft_printf("Hello ft");
//}
