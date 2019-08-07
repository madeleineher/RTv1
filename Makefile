# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/05 07:58:15 by mhernand          #+#    #+#              #
#    Updated: 2019/07/25 15:34:11 by mhernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1

INC = includes/rtv1.h

CFLAGS = -Wall -Werror -Wextra -g3 # remove g3 flag

CC = gcc

SRCS = main.c parser.c start_rtv1.c touch.c draw_sphere.c

OBJS = $(SRCS:.c=.o)

L_FOLD = libft/

L_TARG = libft

M_FOLD = minilibx_macos/

LIBMLX = -L ./minilibx_macos/ -lmlx -framework OpenGL -framework Appkit

superfast:
	@make -j8 all

all: 
	@make $(NAME)

$(NAME):$(OBJS) | $(L_TARG)
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a $(LIBMLX) -o $(NAME)
	@touch .gitignore
	@echo "*.o" > .gitignore
	@echo "*.a" >> .gitignore

%.o: %.c $(INC)
	$(CC) $(CFLAGS) $< -c

$(L_TARG):
	@make -C $(L_FOLD) all
	@make -C $(M_FOLD)

clean:
	@make -C $(L_TARG) clean
	@make -C $(M_FOLD) clean
	@rm -rf $(OBJS)
	@echo "RTv1 is clean !"

fclean: clean
	@make -C $(L_TARG) fclean
	@rm -rf $(NAME)
	@echo "... and fclean too !"

re: fclean all

.PHONY: all clean fclean all libft
