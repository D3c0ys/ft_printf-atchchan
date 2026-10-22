/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchchan <atchchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 23:48:43 by atchchan          #+#    #+#             */
/*   Updated: 2026/10/22 23:58:58 by atchchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	putformat(char c, va_list args)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'p')
		ft_putptr(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 'u')
		ft_putunbr((unsigned int)va_arg(args, int));
	else if (c == 'x')
		ft_puthex(va_arg(args, unsigned int), 0);
	else if (c == 'X')
		ft_puthex(va_arg(args, unsigned int), 1);
	else if (c == '%')
		ft_putchar_fd('%', 1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*p;

	p = (char *)format;
	va_start(args, format);
	while (*p)
	{
		if (*p == '%' && *(p + 1))
			putformat(*(++p), args);
		else
			ft_putchar_fd(*p, 1);
		p++;
	}
	va_end(args);
	return (0);
}

//int main(void)
//{
//	ft_printf("Hello ft");
//}
