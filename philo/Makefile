NAME = philo
INCLUDES = philo.h
DEFS = 		philo.c \
            initialization.c \
            philo_utils.c \
            time_manipulate.c \


OBJS = $(DEFS:.c=.o)

all: $(NAME)

%.o: %.c $(INCLUDES)
	gcc -Wall -Werror -Wextra -c $< -o $@

$(NAME): $(OBJS) $(INCLUDES)
	gcc -Wall -Werror -Wextra $(OBJS) -o $(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)


re: fclean all