# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 00:10:02 by jlucas-s          #+#    #+#              #
#    Updated: 2023/03/15 21:57:13 by jlucas-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			minishell

FLAGS =			-Werror -Wall -Wextra

CC =			cc

GREEN =			\033[1;32m 
YELLOW =		\033[1;33m 
RED =			\033[1;31m 
NOCOLOR =		\033[0m

LIBFTPATH =		./lib
LIBFT =			./lib/libft.a

SRCS =			src/main.c					\
				src/linked_list.c			\
				src/free.c					\
				src/fork.c					\
				src/terminal_line.c			\
				src/identify_exec.c			\
				src/split_command.c			\
				src/pipe.c					\
				src/commands/exit.c			\
				src/commands/execve.c		\
				src/commands/echo.c			\
				src/commands/cd_utils.c		\
				src/commands/cd.c			\
				src/commands/unset.c		\
				src/commands/export.c		\
				src/redirects/output.c		\
				src/redirects/input.c		\

OBJS_DIR = 		./objects
OBJS =			${SRCS:%.c=$(OBJS_DIR)/%.o}

all: ${NAME}

${NAME}: ${OBJS}
	@ echo "${YELLOW}-=- Compiling... -=-${NOCOLOR}"
	@ make -s -C ${LIBFTPATH} 
	@ $(CC) $(FLAGS) $(OBJS) $(LIBFT) -lreadline -o $(NAME)
	@ echo "${GREEN}-=- MINISHELL MANDATORY SUCCESSFUL COMPILED -=-${NOCOLOR}"
	
$(OBJS_DIR)/%.o: %.c
	@ mkdir -p $(dir $@)
	@ $(CC) $(FLAGS) -c $< -o $@

clean:
	@ make fclean -s -C ${LIBFTPATH}
	@ rm -rf $(OBJS_DIR)
	@ echo "${RED}-=- CLEANED -=-${NOCOLOR}"

fclean: clean
	@ rm -f $(NAME)

re: fclean all

run: ${NAME}
	@./$(NAME)

valgrind: ${NAME}
	valgrind --leak-check=full --suppressions=readline.supp --show-leak-kinds=all --track-origins=yes ./$(NAME)

sla:
	./a.out

.PHONY: all clean fclean run valgrind
