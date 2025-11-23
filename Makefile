# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brendos- <brendos-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/20 09:46:57 by brendos-          #+#    #+#              #
#    Updated: 2025/11/22 15:12:28 by brendos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Push_Swap Makefile

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = \
    push_swap_main.c \
    sort_main.c \
    sort_small_cases.c \
    sort_radix.c \
    sort_utils.c \
    parse_input.c \
    parse_utils.c \
    dlist_core.c \
    dlist_operations.c \
    dlist_destroy.c \
    push_and_swap_op.c \
    rotate_op.c \
    reverse_rotate_op.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re