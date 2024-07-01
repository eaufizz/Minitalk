NAME = libftprintf.a 
LIBFT = libft/libft.a
SRCS = \
		ft_printf.c \
		format_processor.c \
		ft_putchr.c \
		ft_putstr.c \
		ft_putptr.c \
		ft_putnbr.c \
		ft_uitoa.c \
		ft_itoh.c

OBJS = $(SRCS:.c=.o)
LSRCS =  \
		ft_isalpha.c\
		ft_isdigit.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isprint.c\
		ft_strlen.c\
		ft_memset.c\
		ft_bzero.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_strlcpy.c\
		ft_strlcat.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strncmp.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_strnstr.c\
		ft_atoi.c\
		ft_calloc.c\
		ft_strdup.c\
		ft_substr.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_split.c\
		ft_itoa.c\
		ft_strmapi.c\
		ft_striteri.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c
OBJS = $(SRCS:.c=.o)
CC = cc -Wall -Wextra -Werror

all: $(NAME)
$(NAME): $(OBJS) $(LIBFT)
	ar rcs $(NAME) $(OBJS) $(LIBFT)
$(OBJS): $(SRCS) $(LIBFT)
	$(CC) -c $< -o $@ -Ilibft
$(LIBFT): 
	make -C libft
clean:
	rm -f $(OBJS)
	make clean -C libft
fclean: clean
	rm -f $(NAME)
	make fclean -C libft
re: fclean all
.PHONY:all clean fclean re