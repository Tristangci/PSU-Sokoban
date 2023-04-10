##
## EPITECH PROJECT, 2023
## my_sokoban
## File description:
## make
##

ECHO	=	/bin/echo -e
RED		=	"\e[0;31m"
GREEN	=	"\e[32m"
DEFAULT	=	"\e[0m"
CLAIR	=	"\e[1m"
DEL		=	[DELETE]

CFLAGS	=	-Wall -Wextra -I ./include/ -g3 -L ./lib -lncurses
OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

SRC	=	src/main.c	\
		src/functions.c	\
		src/cond.c	\
		src/cond_x.c

NAME_LIB	=

all: message lib $(NAME)

message:
	@$(ECHO) $(CLAIR) "\n  [?] CONPILATION...\n" $(DEFAULT)

$(NAME): $(OBJ)
	@$(ECHO)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(NAME_LIB)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(NAME_LIB) &&	\
		$(ECHO) $(GREEN) "\n  [✔] COMPILED:" "$(NAME)\n" $(DEFAULT) ||	\
		$(ECHO) $(RED) "\n  [✘] BUILD FAILED:" "$(NAME)\n" $(DEFAULT)

lib:

lib_clean:

lib_fclean:

clean: lib_clean
	@rm -f $(OBJ) &&	\
		$(ECHO) $(RED) $(CLAIR) "$(DEL)" $(RED) "OBJ -> $(OBJ)" $(DEFAULT)
fclean: lib_fclean
	@rm -f $(OBJ) &&	\
		$(ECHO) $(RED) $(CLAIR) "$(DEL)" $(RED) "OBJ -> $(OBJ)" $(DEFAULT)
	@rm -f $(NAME) &&	\
		$(ECHO) $(RED) $(CLAIR) "$(DEL)" $(RED) "NAME -> $(NAME)" $(DEFAULT)

re: fclean all

.PHONY: all message $(NAME) lib lib_clean lib_fclean clean fclean
