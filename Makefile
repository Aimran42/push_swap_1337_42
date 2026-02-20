# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momahdam <momahdam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/24 13:47:31 by momahdam          #+#    #+#              #
#    Updated: 2026/02/09 17:59:09 by momahdam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker

CC = cc
FLAGS = -Wall -Wextra -Werror

SRCS = ft_check_input.c \
ft_fill_a.c \
ft_handle_sort.c \
libft_atoi.c \
libft_lists.c \
libft_split.c \
libft_strjoin.c \
op_push.c \
op_rotations.c \
op_swaps.c \
op_reverse.c \
parse_args.c \
parse_helpers.c \
push_swap.c \
sort_chunks.c \
sort_edge_cases.c \
sort_helpers.c

SRCS_BONUS = $(wildcard *_bonus.c)
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
HEADER = push_swap.h
HEADER_BONUS = push_swap_bonus.h

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

%_bonus.o: %_bonus.c $(HEADER_BONUS)
	$(CC) $(FLAGS) -c $< -o $@

bonus: $(OBJS_BONUS)
	$(CC) $(FLAGS) $(OBJS_BONUS) -o $(BONUS_NAME)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re
