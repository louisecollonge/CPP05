#Variables

NAME = bureaucrat
CC = c++
CFLAGS = -Wall -Wextra -Werror -g -std=c++98

SRC =	main.cpp \
		Bureaucrat.cpp

OBJ_DIR = obj
OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

#Rules

all: $(NAME)

$(NAME) : $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
