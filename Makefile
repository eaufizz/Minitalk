CC = cc -Wall -Wextra -Werror
LIB = ft_printf/libftprintf.a
all:server client

bonus:server client

server:server.c $(LIB)
	$(CC) -o server server.c $(LIB)

client:client.c $(LIB)
	$(CC) -o client client.c $(LIB)

$(LIB):
	make -C ft_printf all

clean:
	make -C ft_printf clean

fclean: clean
	rm -f server client $(LIB)

re: fclean all

.PHONY: all bonus clean fclean re