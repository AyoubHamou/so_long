# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 22:37:28 by ahamou            #+#    #+#              #
#    Updated: 2023/02/25 21:21:52 by ahamou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

MLX =  -lmlx -framework OpenGL -framework AppKit

CFLAGS += -Wextra -Werror -Wall -I includes

SRCS = sources/so_long.c sources/which_path.c sources/map_check.c sources/valid_path.c\
	sources/display_map.c sources/moves.c utils/error_message.c utils/read_line.c utils/ft_free.c\
	sources/directions.c sources/mlx_funcs.c

LIBFT = libft/ft_bzero.c libft/ft_calloc.c\
	libft/ft_split.c libft/ft_strdup.c libft/ft_strlen.c\
	libft/ft_strncmp.c libft/ft_substr.c libft/ft_strjoin.c libft/ft_swap.c\
	libft/ft_putnbr.c libft/ft_itoa.c libft/ft_strrchr.c

OBJS = $(SRCS:.c=.o) $(LIBFT:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		@cc $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)

clean :
		rm -rf $(OBJS)
		
fclean : clean
		rm -rf $(NAME)

re : fclean all