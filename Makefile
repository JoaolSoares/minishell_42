# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 00:10:02 by jlucas-s          #+#    #+#              #
#    Updated: 2023/01/18 20:00:16 by jlucas-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			minishell

# FLAGS =			-Werror -Wall -Wextra

CC =			cc

GREEN =			\033[1;32m 
NOCOLOR =		\033[0m

LIBFTPATH =		./lib
LIBFT =			./lib/libft.a

SRCS =			main.c		\
				exec.c		\
				fork.c		\

OBJS_DIR = 		./objects
OBJS =			$(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))


all: ${NAME}

${NAME}: ${OBJS}
	@ make -C ${LIBFTPATH}
	@ $(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@ echo "${GREEN}-=- MINISHELL MANDATORY SUCCESSFUL COMPILED -=-${NOCOLOR}"

$(OBJS_DIR)/%.o: src/%.c
	@ mkdir -p $(OBJS_DIR)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@ rm -rf $(OBJS_DIR)
	@ make fclean -C ${LIBFTPATH}

rmv:
	@ rm -f $(NAME)

fclean: rmv clean

re: fclean all

refast: rmv all clean

.PHONY: all clean rmv fclean rerefast
