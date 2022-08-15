SRC = main.c arrays_basics.c check_win.c game_output.c get_user.c turn_quarter.c
NAME = unix_exe
SRCS = $(addprefix srcs/, $(SRC))
HDR = includes
RM = /bin/rm
CC = gcc
CFLAGS = -Wall -Werror -Wextra
CLEAR = clear

all: $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -I $(HDR) -o $(NAME)
	$(CLEAR) && ./$(NAME)
clean:
	$(RM) $(NAME)
