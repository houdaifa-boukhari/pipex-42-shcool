NAME = pipex
SRC = pipex_bonus.c split_.c tools.c tools_strings.c get_environ_bonus.c tools_lists.c
HEADER = pipex.h
OBJS = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS) $(HEADER)
	@$(CC) $(OBJS) -o $(NAME) 

clean :
		@rm -f $(OBJS)
fclean : clean
		@rm -f $(NAME)
re : clean all