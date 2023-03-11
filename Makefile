Name = pipex.a
CC = cc
RM = rm -f
AR = ar rc
ouput = pipex
FLG = -Wall -Wextra -Werror
libft = libft.a
src = pipex.c f_free.c path_with_cmd.c

OBJ = $(src:.c=.o)

all : $(Name) $(ouput)

$(Name) : $(OBJ)
	cd libft && make
	$(AR) $(Name)  $(OBJ)

%.o: %.c pipex.h
	$(CC) $(FLG) -c $<

$(ouput):
	$(CC) $(FLG) $(Name) $(libft) -o $(ouput)

clean:
	cd libft && make clean
	$(RM) $(OBJ)

fclean: clean
	cd libft && make fclean
	$(RM) $(Name) $(libft) $(ouput)

re: fclean all
