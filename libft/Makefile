# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 18:22:03 by mennaji           #+#    #+#              #
#    Updated: 2023/02/07 18:18:03 by mennaji          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILES 	= ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strlen.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strnstr.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c\
		ft_strjoin.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strtrim.c \
		ft_itoa.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putnbr_fd.c \
		ft_putendl_fd.c \
		ft_strmapi.c \
		ft_split.c \
		ft_striteri.c \

BONUS = ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \




OBJS =	$(FILES:.c=.o)
BOBJS =	$(BONUS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM		= rm -rf
HDRS 	= libft.h

.c.o = ${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

bonus: $(NAME) $(BOBJS)
	ar rcs $(NAME) $(BOBJS)

all: $(NAME)

clean:
	${RM} $(OBJS) $(BONUS_BOBJS)

fclean: clean
	${RM} $(NAME)

re: fclean all

.PHONY: all clean fclean re
