GCC = gcc -Wall -Wextra -Werror
CLIENT = client
SERVER = server
LIB = 
MAKE = make
CLI = ./client.c
SER = ./server.c
CLILIB = client.a
SERLIB = server.a
CLIOBJS = $(CLI:.c=.o)
SEROBJS = $(SER:.c=.o)

BCLIENT = client_bonus
BSERVER = server_bonus
BCLI = ./client_bonus.c
BSER = ./server_bonus.c
BCLILIB = client_bonus.a
BSERLIB = server_bonus.a
BCLIOBJS = $(BCLI:.c=.o)
BSEROBJS = $(BSER:.c=.o)

# CLIBN = ./client_bonus.c
# SERBN = ./server_bonus.c
# CLIBNOBJS = $(CLIBN:.c=.o)
# SERBNOBJS = $(SERBN:.c=.o)
all: $(CLIENT) $(SERVER)

bonus: $(BCLIENT) $(BSERVER)

$(CLIENT): $(CLIOBJS)
	$(MAKE) -C "./libft/"
	cp ./libft/libft.a $(CLILIB)
	ar -rc $(CLILIB) $(CLIOBJS)
	$(GCC) ./$(CLILIB) -o $(CLIENT)

$(SERVER):$(SEROBJS)
	$(MAKE) -C "./libft/"
	cp ./libft/libft.a $(SERLIB)
	ar -rc $(SERLIB) $(SEROBJS)
	$(GCC) ./$(SERLIB) -o $(SERVER)

$(BCLIENT): $(BCLIOBJS)
	$(MAKE) -C "./libft/"
	cp ./libft/libft.a $(BCLILIB)
	ar -rc $(BCLILIB) $(BCLIOBJS)
	$(GCC) ./$(BCLILIB) -o $(BCLIENT)

$(BSERVER):$(BSEROBJS)
	$(MAKE) -C "./libft/"
	cp ./libft/libft.a $(BSERLIB)
	ar -rc $(BSERLIB) $(BSEROBJS)
	$(GCC) ./$(BSERLIB) -o $(BSERVER)

%.o : %.c
	$(GCC) -I ./ -c -o $@ $^

clean: 
	$(MAKE) clean -C ./libft/
	rm -rf $(SEROBJS)
	rm -rf $(CLIOBJS)

fclean: clean
	$(MAKE) fclean -C ./libft/
	rm -rf $(SERLIB)
	rm -rf $(CLILIB)
	rm -rf $(SERVER)
	rm -rf $(CLIENT)

re: fclean all

clean_bonus: 
	$(MAKE) clean -C ./libft/
	rm -rf $(BSEROBJS)
	rm -rf $(BCLIOBJS)

fclean_bonus: clean_bonus
	$(MAKE) fclean -C ./libft/
	rm -rf $(BSERLIB)
	rm -rf $(BCLILIB)
	rm -rf $(BSERVER)
	rm -rf $(BCLIENT)

re_bonus: fclean_bonus bonus
