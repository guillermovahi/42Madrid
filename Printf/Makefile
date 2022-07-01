# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guvargas <guvargas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/01 17:01:37 by guvargas          #+#    #+#              #
#    Updated: 2022/07/01 17:37:47 by guvargas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS	= ft_printf.c ft_hex.c ft_numbers.c ft_text.c

OBJS	= ${SRCS:.c=.o}

SRCSB	= ft_printf.c ft_hex.c ft_numbers.c ft_text.c

OBJB	= ${SRCSB:.c=.o}

NAME	= libftprintf.a

CC	= gcc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror

AR = ar rc

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
				${AR} ${NAME} ${OBJS}
				ranlib ${NAME}

bonus:		all ${OBJB}
				@make OBJS="${OBJB}"

all:		${NAME}

clean:
				${RM} ${OBJS} ${OBJB}

fclean: 	clean
				${RM} ${NAME}

re: 		fclean all

rebonus:	fclean bonus

.PHONY:		all bonus clean fclean re rebonus