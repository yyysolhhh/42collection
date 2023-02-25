# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yesollee <yesollee@student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/03 16:28:06 by yesollee          #+#    #+#              #
#    Updated: 2023/02/25 14:42:56 by yesollee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	 = fractol
LIBFT	 = libft.a
MLX		 = libmlx.a

LIBFTDIR = Libft
MLXDIR	 = minilibx
SRCDIR	 = src
SRCBDIR  = src/bonus
OBJDIR   = obj
INC  	 = include

SRCS_F	 = main.c \
		   handle_error.c \
		   handle_key_event.c \
		   handle_mouse_event.c \
		   window.c \
		   init_fractal.c \
		   set_fractal.c \
		   draw_fractal.c \
		   color.c

SRCS_M	 = $(notdir $(SRCDIR)/$(SRCS_F))
SRCS_B	 = $(patsubst .c, _bonus.c, $(notdir $(addprefix $(SRCBDIR)/, $(SRCS_F))))
OBJS_M	 = $(addprefix $(OBJDIR)/, $(SRCS_M:.c=.o))
OBJS_B	 = $(addprefix $(OBJDIR)/, $(SRCS_B:.c=_bonus.o))

CC		 = gcc
CFLAGS	 = -Wall -Wextra -Werror
RM		 = rm -rf
MLXFLAGS = -L$(MLXDIR) -lmlx -framework OpenGL -framework AppKit -lz

ifdef WITH_BONUS
	OBJS   = $(OBJS_B)
else
	OBJS   = $(OBJS_M)
endif

all:		$(NAME)

bonus:
			make WITH_BONUS=1 all

$(OBJDIR)/%.o:	$(SRCDIR)/%.c $(INC)/fractol.h
			mkdir -p $(OBJDIR)
			$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

$(OBJDIR)/%.o:	$(SRCBDIR)/%.c $(INC)/fractol_bonus.h
			mkdir -p $(OBJDIR)
			$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

$(NAME):	$(LIBFTDIR)/$(LIBFT) $(MLXDIR)/$(MLX) $(OBJS)
			$(CC) $(CFLAGS) $(MLXFLAGS) -L./$(LIBFTDIR) -lft -o $(NAME) $(OBJS)

$(LIBFTDIR)/$(LIBFT): 
			make -C $(LIBFTDIR)

$(MLXDIR)/$(MLX):
			make -C $(MLXDIR)

clean:
			$(RM) $(OBJDIR)
			make clean -C $(LIBFTDIR)
			make clean -C $(MLXDIR)

fclean:		clean
			$(RM) $(NAME)
			$(RM) $(LIBFTDIR)/libft.a

re:			fclean all

.PHONY:		all clean fclean re bonus
