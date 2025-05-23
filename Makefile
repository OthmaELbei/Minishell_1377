CC = cc
# FLAGS = -Wall -Wextra -Werror -fsanitize=address
FLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC = parsing/main.c parsing/tokenization.c parsing/grabage.c parsing/error.c\
	parsing/expand.c parsing/ft_rename.c parsing/ft_herdoc.c parsing/parsing.c\
	libft/ft_putstr_fd.c libft/ft_strlen.c libft/ft_cmp.c libft/ft_strjoin.c\
	libft/linked_list.c libft/ft_substr.c libft/ft_strdup.c libft/ft_isprint.c\
	libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isdigit.c libft/ft_strncmp.c\
	libft/ft_strndup.c libft/ft_allocate.c libft/ft_strcat.c libft/ft_strncpy.c\
	libft/ft_memset.c libft/ft_strcmp.c libft/ft_split.c\
	peltend/env.c libft/ft_lstadd_back_bonus.c libft/ft_lstdelone_bonus.c libft/ft_lstnew_bonus.c\
	libft/ft_lstsize_bonus.c peltend/ft_tchc_data.c peltend/pwd.c peltend/echo.c\
	peltend/unset.c peltend/exit.c peltend/cd.c peltend/export.c peltend/tchcke_pluss.c\
	peltend/ft_thchk_cotchen.c libft/ft_strchr.c

OBJ = $(SRC:.c=.o)

NAME = minishell

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) -lreadline

parsing/%.o: parsing/%.c include/minishell.h
	$(CC) $(FLAGS) -c $< -o $@

libft/%.o: libft/%.c include/minishell.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
