NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCS = ft_printf.c

UTILS_DIR = utils
UTILS_SRCS = $(addprefix $(UTILS_DIR)/, ft_puthex.c ft_putptr.c ft_putunbr.c ft_putnbr.c ft_putstr.c ft_putchr.c)

HEADERS = ft_printf.h $(UTILS_DIR)/ft_printf_utils.h

OBJS = $(SRCS:.c=.o) $(UTILS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
