#include <stdarg.h> // for variadic function
#include <stdio.h>

int sum(int count, ...) {
	int total = 0;
	va_list arg;
	va_start(arg, count); // numbers of input
	
	for(int i=0; i < count; i++)
		total += va_arg(arg, int);

	va_end(arg);
	return total;
}

int main()
{
	int n = sum(4,1,2,3,4);
	printf("%d\n", n);
}
