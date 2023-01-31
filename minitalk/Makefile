# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yesollee <yesollee@student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/03 16:28:06 by yesollee          #+#    #+#              #
#    Updated: 2023/01/31 15:10:49 by yesollee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	 = server
CLIENT	 = client
SERVER_B = server
CLIENT_B = client
LIBFT	 = libft.a

LIBFTDIR = Libft
SRCDIR	 = src
OBJDIR   = obj
INC  	 = include

SRCS_SV	 = server.c
SRCS_CL	 = client.c
OBJS_SV	 = $(OBJDIR)/$(SRCS_SV:.c=.o)
OBJS_CL	 = $(OBJDIR)/$(SRCS_CL:.c=.o)

SRCS_SB	 = server_bonus.c
SRCS_CB	 = client_bonus.c
OBJS_SB	 = $(OBJDIR)/$(SRCS_SB:.c=.o)
OBJS_CB	 = $(OBJDIR)/$(SRCS_CB:.c=.o)

CC		 = gcc
CFLAGS	 = -Wall -Wextra -Werror
RM		 = rm -rf

ifdef WITH_BONUS
	OBJS   = $(OBJS_SB)
	OBJS_C = $(OBJS_CB)
else
	OBJS   = $(OBJS_SV)
	OBJS_C = $(OBJS_CL)
endif

all:		$(NAME) $(CLIENT)

bonus:
			make WITH_BONUS=1 all

$(OBJDIR)/%.o:	$(SRCDIR)/%.c
			mkdir -p $(OBJDIR)
			$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

$(NAME):	$(LIBFTDIR)/$(LIBFT) $(OBJS)
			$(CC) $(CFLAGS) -L./$(LIBFTDIR) -lft -o $(NAME) $(OBJS)

$(CLIENT):	$(LIBFTDIR)/$(LIBFT) $(OBJS_C)
			$(CC) $(CFLAGS) -L./$(LIBFTDIR) -lft -o $(CLIENT) $(OBJS_C)

$(LIBFTDIR)/$(LIBFT): 
			make -C $(LIBFTDIR)

clean:
			$(RM) $(OBJDIR)
			make clean -C $(LIBFTDIR)

fclean:		clean
			$(RM) $(NAME) $(CLIENT)
			$(RM) $(LIBFTDIR)/libft.a

re:			fclean all

.PHONY:		all clean fclean re bonus
