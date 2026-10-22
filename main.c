// Here are the requirements:
// • Do not implement the buffer management of the original printf().
// • Your function has to handle the following conversions: cspdiuxX%
// • Your function will be compared against the original printf().
// • You must use the command ar to create your library.
//
// Using the libtool command is forbidden.
// • Your libftprintf.a has to be created at the root of your repository.
// • Your header file must be named ft_printf.h and must contain the prototype of your ft_printf() function.
//
// You have to implement the following conversions:
// • %c Prints a single character.
// • %s Prints a string (as defined by the common C convention).
// • %p The void * pointer argument has to be printed in hexadecimal format.
// • %d Prints a decimal (base 10) number.
// • %i Prints an integer in base 10.
// • %u Prints an unsigned decimal (base 10) number.
// • %x Prints a number in hexadecimal (base 16) lowercase format.
// • %X Prints a number in hexadecimal (base 16) uppercase format.
// • %% Prints a percent sign.

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>
#include <unistd.h>

static void	putformat(char c, va_list args)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'p')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'd')
		ft_putstr_fd("Unimplement", 1);
	else if (c == 'i')
		ft_putstr_fd("Unimplement", 1);
	else if (c == 'u')
		ft_putstr_fd("Unimplement", 1);
	else if (c == 'x')
		ft_putstr_fd("Unimplement", 1);
	else if (c == 'X')
		ft_putstr_fd("Unimplement", 1);
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

int	main(void)
{
	char a[] = "Hello ft";
	printf("%lu", (unsigned long)&a);
	//ft_printf("%s %s\n", a, "42");
}
