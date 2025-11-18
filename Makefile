NAME        = libgnl.a

SRC         = src/get_next_line.c src/get_next_line_utils.c
BONUS_SRC   = src/get_next_line_bonus.c src/get_next_line_utils_bonus.c

OBJ         = $(SRC:.c=.o)
BONUS_OBJ   = $(BONUS_SRC:.c=.o)

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -Iinclude

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

bonus: $(OBJ) $(BONUS_OBJ)
	@ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)

%.o: %.c include/get_next_line.h include/get_next_line_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
