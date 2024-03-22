NAME = ../pipex
SRC = pipex_bonus.c split_bonus.c free_tools_bonus.c tools_string2_bonus.c tools_strings_bonus.c \
	get_environ_bonus.c tools_lists_bonus.c ../get_next_line/get_next_line.c \
	../get_next_line/get_next_line_utils.c her_doc_bonus.c
HEADER = pipex_bonus.h
OBJS = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) 
%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c  $< -o $@
clean :
		@rm -f $(OBJS)
fclean : clean
		@rm -f $(NAME)
re : clean all