NAME = pipex

CFLAGS = -Wall -Wextra -Werro
CC = cc
AR = ar -rcs

MAN_DIR = mandatory
SRC = $(MAN_DIR)/pipex.c $(MAN_DIR)/parsing_split.c \
		$(MAN_DIR)/utils.c $(MAN_DIR)/ft_error.cc

OBJ = $(SRC:.c:.o)

all: $(NAME)

$(NAME): $(OBJ)

%.o: %.c pipex.h
	$(CC) $(CFLAGS) $< -o $@
