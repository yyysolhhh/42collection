# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By:          <        @student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/03 16:28:06 by                   #+#    #+#              #
#    Updated: 2023/03/21 13:55:14 by                  ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	 = push_swap
BONUS	 = checker
LIBFT	 = libft.a

LIBFTDIR = Libft
SRCDIR	 = src/push_swap_src
SRCDIR_B = src/checker_src
OBJDIR   = obj
INC  	 = include

SRCS_F	 = main.c \
		   error.c \
		   init.c \
		   parsing.c \
		   pushswap_utils.c \
		   sorting.c \
		   small_sorting.c \
		   swap.c \
		   push.c \
		   rotate.c \
		   reverse_rotate.c \
		   clean.c

SRCS_BF	 = checker.c \
		   error.c \
		   init.c \
		   parsing.c \
		   pushswap_utils.c \
		   swap.c \
		   push.c \
		   rotate.c \
		   reverse_rotate.c \
		   clean.c \
		   operation.c

SRCS	 = $(notdir $(SRCDIR)/$(SRCS_F))
SRCS_B	 = $(notdir $(SRCDIR_B)/$(SRCS_BF))

OBJS	 = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
OBJS_B	 = $(addprefix $(OBJDIR)/, $(SRCS_B:.c=.o))

CC		 = cc
CFLAGS	 = -Wall -Wextra -Werror
RM		 = rm -rf

all:		$(NAME)

bonus:		$(BONUS)

$(OBJDIR)/%.o:	$(SRCDIR_B)/%.c $(INC)/checker.h
			mkdir -p $(OBJDIR)
			$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

$(OBJDIR)/%.o:	$(SRCDIR)/%.c $(INC)/pushswap.h
			mkdir -p $(OBJDIR)
			$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

$(NAME):	$(LIBFTDIR)/$(LIBFT) $(OBJS)
			$(CC) $(CFLAGS) -L./$(LIBFTDIR) -lft -o $(NAME) $(OBJS)

$(BONUS):	$(LIBFTDIR)/$(LIBFT) $(OBJS_B)
			$(CC) $(CFLAGS) -L./$(LIBFTDIR) -lft -o $(BONUS) $(OBJS_B)

$(LIBFTDIR)/$(LIBFT): 
			make -C $(LIBFTDIR)

clean:
			$(RM) $(OBJDIR)
			make clean -C $(LIBFTDIR)

fclean:		clean
			$(RM) $(NAME) $(BONUS)
			#make fclean -C $(LIBFTDIR)
			$(RM) $(LIBFTDIR)/libft.a

re:			fclean all

.PHONY:		all clean fclean re bonus
