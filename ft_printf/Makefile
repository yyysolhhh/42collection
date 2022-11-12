# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yesollee <yesollee@student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/03 16:28:06 by yesollee          #+#    #+#              #
#    Updated: 2022/10/28 13:38:34 by yesollee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	 = libftprintf.a

LIBFT	 = libft

SRCDIR	 = src

OBJDIR   = obj

INCLUDE  = include

SRCS	 = $(notdir $(wildcard $(SRCDIR)/*.c))

OBJFILES = $(SRCS:.c=.o)

OBJS 	 = $(patsubst %.o, $(OBJDIR)/%.o, $(OBJFILES))

CC		 = gcc

CFLAGS	 = -Wall -Wextra -Werror

AR		 = ar

ARFLAGS	 = rcs

RM		 = rm -rf

$(OBJDIR)/%.o:	$(SRCDIR)/%.c $(OBJDIR)
			$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

$(NAME):	$(OBJS)
			make -C $(LIBFT)
			cp $(LIBFT)/libft.a .
			mv libft.a $(NAME)
			$(AR) $(ARFLAGS) $@ $^

$(OBJDIR):
			mkdir -p $(OBJDIR)

all:		$(NAME)

clean:
			$(RM) $(OBJDIR)
			make clean -C $(LIBFT)

fclean:		clean
			$(RM) $(NAME)
			$(RM) $(LIBFT)/libft.a

re:			fclean all

.PHONY:		all clean fclean re 
