GCC = gcc -Wall -Wextra -Werror
NAME = libft.a
PRINTFS = ./ft_printf/ft_printf.c		\
		  ./ft_printf/print_char.c	\
		  ./ft_printf/print_str.c		\
		  ./ft_printf/print_ptr.c		\
		  ./ft_printf/print_dexint.c	\
		  ./ft_printf/print_unsign.c	\
		  ./ft_printf/print_hexlowup.c

GNLS =	./get_next_line/get_next_line_utils_bonus.c	\
		./get_next_line/get_next_line_bonus.c	\

LIBFTS =	./ft_is/ft_isalpha.c		\
			./ft_is/ft_isdigit.c		\
			./ft_is/ft_isalnum.c		\
			./ft_is/ft_isascii.c		\
			./ft_is/ft_isprint.c		\
			./ft_mem/ft_memset.c		\
			./ft_mem/ft_memcpy.c		\
			./ft_mem/ft_memmove.c		\
			./ft_mem/ft_memchr.c		\
			./ft_mem/ft_memcmp.c		\
			./ft_str/ft_strlen.c		\
			./ft_str/ft_strdup.c	\
			./ft_str/ft_strlcpy.c		\
			./ft_str/ft_strlcat.c		\
			./ft_str/ft_strchr.c		\
			./ft_str/ft_strrchr.c		\
			./ft_str/ft_strncmp.c		\
			./ft_str/ft_strnstr.c		\
			./ft_str/ft_strjoin.c		\
			./ft_str/ft_strtrim.c		\
			./ft_str/ft_strmapi.c		\
			./ft_str/ft_striteri.c		\
			./ft_str/ft_substr.c		\
			./ft_etc/ft_itoa.c			\
			./ft_etc/ft_split.c			\
			./ft_etc/ft_bzero.c			\
			./ft_etc/ft_atoi.c			\
			./ft_etc/ft_toupper.c		\
			./ft_etc/ft_tolower.c		\
			./ft_etc/ft_calloc.c		\
			./ft_put/ft_putchar_fd.c	\
			./ft_put/ft_putstr_fd.c		\
			./ft_put/ft_putendl_fd.c	\
			./ft_put/ft_putnbr_fd.c		\
			./ft_lst/ft_lstnew_bonus.c		\
			./ft_lst/ft_lstadd_front_bonus.c	\
			./ft_lst/ft_lstsize_bonus.c		\
			./ft_lst/ft_lstlast_bonus.c		\
			./ft_lst/ft_lstadd_back_bonus.c	\
			./ft_lst/ft_lstdelone_bonus.c	\
			./ft_lst/ft_lstclear_bonus.c		\
			./ft_lst/ft_lstiter_bonus.c		\
			./ft_lst/ft_lstmap_bonus.c

OBJS =	$(PRINTFS:.c=.o)	\
		$(GNLS:.c=.o)	\
		$(LIBFTS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rc $@ $^

%.o : %.c
	@$(GCC) -I ./lib/ -c $^ -o $@

clean: 
	@rm -rf $(OBJS) $(BOBJS)

fclean: clean
	@rm -rf $(NAME)

re:
	@make clean
	@make all

.PHONY : all clean fclean re
