NAME = libftprintf.a

PATH_INCLUDE = ./includes/
PATH_SRC = ./sources/

HEADERS = ${PATH_INCLUDE}ft_printf.h
HDR_INC = -I./includes/

C_FLAGS = -Wall -Wextra -Werror -c

SRC = ft_printf_utils.c ft_putstr_fd.c ft_strchr.c ft_strlen.c ft_putchar_fd.c ft_printf.c						
OBJS = ${addprefix $(PATH_SRC), ${SRC:.c=.o}}

RM = rm -rf

%.o : %.c $(HEADERS)
	gcc $(C_FLAGS) $(HDR_INC) $< -o $@

all: ${OBJS} ${NAME}

$(NAME): $(OBJS) $(HEADERS)
	ar rcs $(NAME) $(OBJS) $(HEADERS)
clean:
	$(RM) $(OBJS)


fclean: clean
	$(RM) $(NAME)

re: fclean all