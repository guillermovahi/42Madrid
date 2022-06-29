# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guvargas <guvargas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 16:31:03 by guvargas          #+#    #+#              #
#    Updated: 2022/06/22 17:07:43 by guvargas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CC	= gcc

FLAGS	= -Wall -Werror -Wextra

RM	= rm -f

AR = ar -rcs

MANDATORY_SRCS	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_putchar_fd.c ft_putstr_fd.c ft_itoa.c ft_putendl_fd.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

MANDATORY_OBJ	= ${MANDATORY_SRCS:.c=.o}

BONUS_SRCS	= ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c

BONUS_OBJ	= ${BONUS_SRCS:.c=.o}

.c.o:
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${MANDATORY_OBJ}
				${AR} ${NAME} ${MANDATORY_OBJ}

all:		${NAME}

clean:
				${RM} ${MANDATORY_OBJ} ${BONUS_OBJ}

fclean: 	clean
				${RM} ${NAME}

re: 		fclean all

bonus:		${MANDATORY_OBJ} ${BONUS_OBJ}
				${AR} ${NAME} ${MANDATORY_OBJ} ${BONUS_OBJ}
				
rebonus:	fclean bonus

.PHONY:		all clean fclean re bonus rebonus