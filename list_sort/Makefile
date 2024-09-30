# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swenn <swenn@42angouleme.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/19 21:21:03 by swenn             #+#    #+#              #
#    Updated: 2024/09/30 15:09:14 by swenn            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


################################################################################

NAME		:=	sort_list

OBJS_DIR	:= .objs

SRCS_DIR	:=	src

SRCS		:= sort.c \
			   main.c	

SRCS		:=	$(addprefix $(SRCS_DIR)/, $(SRCS))

OBJS 		:=  $(addprefix $(OBJS_DIR)/, $(SRCS:%.c=%.o))

CC			:= cc

CFLAGS		:= -Wall -Wextra -g

IFLAGS		:= -I ./include

RM			:=	rm -rf

DIR_UP		=	mkdir -p $(@D)

################################################################################

all: $(NAME)

$(NAME):	$(OBJS)
	@$(CC) $(CFLAGS) $(IFLAGS) $^ -o $@

$(OBJS_DIR)/%.o: %.c
	@$(DIR_UP)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS_DIR)
	@$(RM) $(OBJS)
	@printf "$(RED)####  .o removed  ####\n"

fclean: clean
	@printf "$(RED) ####  $(NAME) removed ####\n"
	@$(RM) $(NAME)
re:
	@$(MAKE) fclean
	@$(MAKE) all

################################################################################

RED			=	\033[31;49;1m

################################################################################
