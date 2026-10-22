*This project has been created as part of the 42 curriculum by atchchan.*

# ft_printf

## Description

`ft_printf` is a re-implementation of the C standard library function `printf(3)`.
The goal of the project is to learn how **variadic functions** work in C
(`<stdarg.h>`: `va_start`, `va_arg`, `va_end`) and to build a small, reusable
output library that can be linked into later 42 projects.

The project produces a static library, `libftprintf.a`, which exposes a single
function:

```c
int	ft_printf(const char *format, ...);
```

Like the original, it writes the formatted output to standard output and
returns the number of characters printed.

### Supported conversions

| Conversion | Prints                                             |
|------------|----------------------------------------------------|
| `%c`       | a single character                                 |
| `%s`       | a string (`(null)` if the pointer is `NULL`)       |
| `%p`       | a pointer address in hex, prefixed with `0x` (`(nil)` if `NULL`) |
| `%d`, `%i` | a signed decimal integer                           |
| `%u`       | an unsigned decimal integer                        |
| `%x`       | an unsigned integer in lowercase hexadecimal       |
| `%X`       | an unsigned integer in uppercase hexadecimal       |
| `%%`       | a literal percent sign                             |

An unknown conversion (for example `%k`) is printed as-is: `%` followed by the
character.

### Project structure

```
.
├── Makefile
├── ft_printf.h            # public header
├── ft_printf.c            # format parsing and conversion dispatch
└── utils/
    ├── ft_printf_utils.h  # prototypes of the output helpers
    ├── ft_putchr.c        # %c
    ├── ft_putstr.c        # %s
    ├── ft_putnbr.c        # %d / %i
    ├── ft_putunbr.c       # %u
    ├── ft_puthex.c        # %x / %X (also used by %p)
    └── ft_putptr.c        # %p
```

Every helper writes directly to file descriptor 1 and returns the number of
characters it wrote, so `ft_printf` only has to add those values up.

## Instructions

### Compilation

The library is built with `cc` and the flags `-Wall -Wextra -Werror`.

```sh
make        # build libftprintf.a
make clean  # remove object files
make fclean # remove object files and libftprintf.a
make re     # fclean, then build again
```

### Usage

Include the header and link against the library:

```c
#include "ft_printf.h"

int	main(void)
{
	int	len;

	len = ft_printf("%c %s %p %d %u %x %X %%\n",
			'A', "hi", (void *)0, -42, 42u, 255, 255);
	ft_printf("printed %d characters\n", len);
	return (0);
}
```

```sh
cc -Wall -Wextra -Werror main.c -I. -L. -lftprintf -o test
./test
```

Output:

```
A hi (nil) -42 42 ff FF %
printed 26 characters
```

## Algorithm and data structures

### Parsing: one linear pass over the format string

`ft_printf` walks the format string once, from left to right, with a single
pointer:

1. If the current character is not `%`, it is written as-is and the counter
   is incremented.
2. If it is `%` and another character follows, the pointer moves to that
   character (the *conversion specifier*) and `putformat` is called with it.
3. `putformat` picks the right helper with a chain of `if / else if`
   comparisons, takes the next argument with `va_arg` using the type that
   specifier expects, and returns how many characters were printed.

**Why this approach:** the mandatory part has no flags, field width or
precision, so every conversion is exactly one character after `%`. That means
no tokenizer, state machine or intermediate structure is needed. A single pass
is O(n) in the length of the format string, uses O(1) extra memory and is easy
to read and check against the subject. With only nine specifiers, an
`if / else if` chain is as clear as a lookup table of function pointers and
avoids the extra indirection. A table would be the better choice if the
project grew to support flags (the bonus part).

### Number conversion: recursion over the base

`ft_putnbr`, `ft_putunbr` and `ft_puthex` print numbers recursively. To print
`n` in base `b`, the function first prints `n / b` (the higher digits), then
writes the last digit, `n % b`. The recursion stops when only one digit is
left.

**Why this approach:** digits come out in the right order without a temporary
buffer and without reversing a string, and nothing is allocated with
`malloc`, so there is nothing to free and no allocation can fail. The
recursion depth is at most the number of digits: 10 for a 32-bit decimal
number, 16 for a 64-bit hexadecimal one. That is small enough that stack use
is not a concern.

- **Negative integers:** `ft_putnbr` never negates `n`. It works with the
  sign of each remainder instead (`(n % 10) * ±1`). As a result, `INT_MIN`
  (`-2147483648`) is handled correctly, without the overflow that `-n` would
  cause.
- **Hexadecimal:** digits are looked up in a constant string
  (`"0123456789abcdef"` or `"0123456789ABCDEF"`), indexed by `n % 16`. One
  function covers both `%x` and `%X`. It takes an `unsigned long`, so it is
  also reused by `ft_putptr` to print 64-bit addresses.

### Data structures

- **`va_list`:** the only structure the program needs. It is the standard,
  portable way to go through a variable number of arguments of different
  types. It is passed down to `putformat`, which reads exactly one argument
  for each conversion.
- **Constant digit strings:** small read-only lookup tables that turn a digit
  value into its character.
- **An `int` counter:** every helper returns how many characters it wrote, and
  the callers add these values up. This gives `ft_printf` the same return
  value as `printf` without a global variable or a shared buffer.

### Output strategy

The output is written straight to standard output with `write(2)`, without
building a buffer first. This keeps the code simple and makes sure the output
appears in the same order as other `write` calls in the program. The downside
is more system calls than a buffered implementation, which is acceptable at
this scale.

## Resources

- `man 3 printf`: reference behavior for each conversion and the return value
- `man 3 stdarg`: `va_start`, `va_arg`, `va_copy`, `va_end`
- `man 2 write`
- [cppreference: printf](https://en.cppreference.com/w/c/io/fprintf)
- [cppreference: Variadic functions](https://en.cppreference.com/w/c/variadic)
- [GNU C Library manual: Variadic Functions](https://www.gnu.org/software/libc/manual/html_node/Variadic-Functions.html)

### Use of AI

An AI assistant (Claude, through Claude Code) was used for these tasks:

- **Makefile:** helped rewrite the `Makefile` to build `libftprintf.a` with an
  explicit list of source files and header dependencies.
- **Include paths:** found and fixed broken `#include` paths in `utils/` at
  the time libft was still a dependency.
- **README:** drafted this `README.md` from the existing source code.

The design and implementation of `ft_printf` and the `utils/` helpers
(parsing, conversions and return-value counting) were written by the author.
