#include <stdio.h>
//#include "ft_printf.h"

/*
** Compares libc's printf against ft_printf for the same format + args.
** Prints both outputs plus both return values so mismatches are obvious.
*/
//#define TEST(fmt, ...) \
//	do { \
//		int ret_std; \
//		int ret_ft; \
//		printf("---------------------------------------------\n"); \
//		printf("format: \"%s\"\n", fmt); \
//		printf("std: ["); \
//		ret_std = printf(fmt, ##__VA_ARGS__); \
//		printf("] (ret=%d)\n", ret_std); \
//		printf("ft:  ["); \
//		ret_ft = ft_printf(fmt, ##__VA_ARGS__); \
//		printf("] (ret=%d)\n", ret_ft); \
//		if (ret_std != ret_ft) \
//			printf("  ^^^ RETURN VALUE MISMATCH\n"); \
//	} while (0)

int	main(void)
{
	/* basic width */
	printf("[%5d]\n", 42);
	printf("[%5s]\n", "hi");
	printf("[%5c]\n", 'a');
	printf("[%2d]\n", 12345);

	/* '-' : left justify */
	printf("[%-5d]\n", 42);
	printf("[%-5s]\n", "hi");
	printf("[%-5c]\n", 'a');

	/* '0' : zero padding */
	printf("[%05d]\n", 42);
	printf("[%05d]\n", -42);
	printf("[%05x]\n", 255);
	printf("[%-05d]\n", 42);   /* '-' overrides '0' */
	printf("[%08.5d]\n", 42);  /* precision overrides '0' */

	/* '.' precision */
	printf("[%.3s]\n", "hello");
	printf("[%.5d]\n", 42);
	printf("[%.0d]\n", 0);
	printf("[%.d]\n", 0);
	printf("[%.s]\n", "hello");
	printf("[%10.3s]\n", "hello");
	printf("[%-10.3s]\n", "hello");
	printf("[%8.5d]\n", 42);
	printf("[%.5d]\n", -42);

	/* combinations of '-' '0' '.' + width */
	printf("[%-08.3d]\n", 7);
	printf("[%0-8d]\n", 7);

	/* '#' : alternate form (x/X only) */
	printf("[%#x]\n", 255);
	printf("[%#X]\n", 255);
	printf("[%#x]\n", 0);
	printf("[%#8x]\n", 255);
	printf("[%-#8x]\n", 255);
	printf("[%#08x]\n", 255);

	/* '+' : force sign */
	printf("[%+d]\n", 42);
	printf("[%+d]\n", -42);
	printf("[%+5d]\n", 42);
	printf("[%+05d]\n", 42);

	/* ' ' : space for non-negative */
	printf("[% d]\n", 42);
	printf("[% d]\n", -42);
	printf("[% 5d]\n", 42);
	printf("[%+ d]\n", 42);  /* '+' overrides space */

	/* mandatory conversions, quick sanity */
	printf("%c\n", 'A');
	printf("%s\n", "hello");
	printf("%p\n", (void *)main);
	printf("%d\n", -123);
	printf("%i\n", -123);
	printf("%u\n", 123);
	printf("%x\n", 255);
	printf("%X\n", 255);
	printf("%%");

	/* edge cases */
	printf("%s\n", NULL);
	printf("%d\n", 0);
	printf("%d\n", 2147483647);
	printf("%d\n", -2147483648);
	printf("%u\n", 4294967295U);
	printf("");
	printf("no format specifiers here");

	return (0);
}
