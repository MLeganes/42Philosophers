# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 11:49:03 by amorcill          #+#    #+#              #
#    Updated: 2022/03/01 19:07:36 by amorcill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo
CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror -pthread -g

S		=	src/
O		=	obj/
G		=	garbage_collector/

OBJS	= 	$(patsubst $S%.c, $O%.o, $(SRCS))
SRCS	=	$Sphilo.c $Sphilo_parser.c $Sphilo_init.c \
			$Serror.c \
			$Sutils.c \
			$S$Gfree.c \

INCLUDES	=-I ./inc

all:		$(NAME)
# Linking
$(NAME):	$(OBJS)
			@echo "\033[1;32m$(NAME)\033[1;0m\033[32m linking...\033[0m"
			@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
			@echo "\033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"

# Compiling
$O%.o:		$S%.c
			@[ -d $(O) ]	 || mkdir -p $(O)
			@[ -d $(O)$(G) ] || mkdir -p $(O)$(G)
			@echo "\033[1;32m$(NAME)\033[1;0m\033[32m compiling...\033[0m"
			@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
			@rm -rf $(O)
			@rm -rf $(NAME)
			@rm -rf .tmp*
			@echo "\033[31mObjects Files \033[1;31m$(OBJS_LIST)\033[1;0m\033[31mremoved.\033[0m"

fclean: 	clean
			@rm -f $(NAME)
			@echo "\033[1;31m$(NAME)\033[1;0m\033[31m Removed.\033[0m"

re: 		fclean $(NAME)
