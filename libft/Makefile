# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iel-bouh <iel-bouh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/07 13:10:38 by iel-bouh          #+#    #+#              #
#    Updated: 2019/07/22 23:14:50 by iel-bouh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_isascii.c ft_lstdelone.c ft_memchr.c ft_putchar.c ft_putstr.c ft_strcpy.c ft_strjoin.c ft_strncmp.c ft_strsplit.c\
	   ft_isdigit.c	ft_lstiter.c ft_memcmp.c ft_putchar_fd.c ft_putstr_fd.c	ft_strdel.c	ft_strlcat.c ft_strncpy.c ft_strstr.c\
         ft_atoi.c ft_isprint.c	ft_lstmap.c	ft_memcpy.c	ft_putendl.c ft_strcat.c ft_strdup.c ft_strlen.c ft_strnequ.c ft_strsub.c\
          ft_bzero.c ft_itoa.c ft_lstnew.c ft_memdel.c ft_putendl_fd.c ft_strchr.c ft_strequ.c ft_strmap.c ft_strnew.c ft_strtrim.c\
            ft_isalnum.c ft_lstadd.c ft_memalloc.c ft_memmove.c	ft_putnbr.c	ft_strclr.c	ft_striter.c ft_strmapi.c ft_strnstr.c ft_tolower.c\
              ft_isalpha.c ft_lstdel.c	ft_memccpy.c ft_memset.c ft_putnbr_fd.c	ft_strcmp.c	ft_striteri.c ft_strncat.c ft_strrchr.c	ft_toupper.c
C	= gcc
CFLAGS = -Wall -Wextra -Werror 
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
		@ar rc $(NAME) $(OBJ)

%.o		: %.c
		@$(C) $(CFLAGS)  -o $@ -c $<

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all
        