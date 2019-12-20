# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iel-bouh <iel-bouh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/01 14:40:44 by iel-bouh          #+#    #+#              #
#    Updated: 2019/07/22 23:14:36 by iel-bouh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
SRC  = colones.c error.c\
	  	extract.c flags.c free.c\
	  		main.c print.c print1.c\
	  			put.c recursive.c sort.c\
	  			sort_outils.c add.c
C	= gcc
CFLAGS = -Wall -Wextra -Werror 
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
		@make -C libft
		@$(C) $(CFLAGS) libft/libft.a $(OBJ) -o $(NAME)

%.o		: %.c
		$(C) $(CFLAGS)  -o $@ -c $<

clean	:
		@make clean -C libft
		@rm -rf $(OBJ)

fclean  : clean
		@make fclean -C libft
		@rm -f $(NAME)

re : fclean all
