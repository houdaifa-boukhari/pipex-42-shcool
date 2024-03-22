NAME = ../pipex
SRC = pipex.c split_.c free_tools.c tools_string2.c tools_strings.c get_environ.c \
	tools_lists.c 
HEADER = pipex.h
OBJS = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c  $< -o $@
clean :
		@rm -f $(OBJS)
fclean : clean
		@rm -f $(NAME)
re : clean all