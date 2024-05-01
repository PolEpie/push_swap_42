# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pepie <pepie@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/10 00:50:04 by pepie             #+#    #+#              #
#    Updated: 2024/05/01 10:44:52 by pepie            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
LIBFT		=	libft/
LIBFT_A		=	$(addprefix $(LIBFT), libft.a)

CC			=	cc
INCLUDE 	=	./includes/
INCLUDE_LIBFT = $(addprefix $(LIBFT), includes/)
CFLAGS		=	-Wall -Werror -Wextra -g -I$(INCLUDE) -I$(INCLUDE_LIBFT)
RM			=	rm -f
OBJ_DIR		=	objs
SRCS		=	push_swap.c \
				srcs/find_target_first.c \
				srcs/find_target_last.c \
				srcs/move_stack.c \
				srcs/first_part.c \
				srcs/first_part_cost.c \
				srcs/second_part.c \
				srcs/lst_stack.c \
				srcs/lst_stack_2.c \
				srcs/operation_1.c \
				srcs/operation_2.c \
				srcs/operation_3.c

OBJS		=	$(SRCS:/%.c=%.o)

$(NAME):		$(OBJS) $(LIBFT_A)
					$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -lft -o $(NAME)
				@echo "Linked into executable \033[0;32m$(NAME)\033[0m."

test:			$(NAME)
				@./$(NAME) 99 0 25 -38 10 7 42

test_2:			$(NAME)
				@./$(NAME) 34 345 34 4 65 4 23 -5 -456 34 32453 -3456 456 45 6 -56

all:			test

$(LIBFT_A):
				@$(MAKE) -s -C $(LIBFT)
				@echo "Compiled $(LIBFT_A)."

bonus:			all

.c.o:
				@$(CC) $(CFLAGS) -c $< -o $(OBJ_DIR)/$(<:.c=.o)
				@echo "Compiling $<."

localclean:
				@$(RM) -rf $(OBJ_DIR)
				@mkdir $(OBJ_DIR)
				@echo "Removed object files."

clean:			localclean
				@$(MAKE) clean -s -C $(LIBFT)
				@echo "Clean libft."

fclean:			localclean
				@$(MAKE) fclean -s -C $(LIBFT)
				@echo "Full clean libft."
				@$(RM) $(NAME)
				@echo "Removed executable."

re:				fclean all

.PHONY:			all clean fclean re localclean bonus 