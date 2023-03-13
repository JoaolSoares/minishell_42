NAME = libft.a

GREEN =				\033[1;32m
RED =				\033[1;31m 
NOCOLOR	=			\033[0m

SRCS =  src/is_functions/ft_isalnum.c		\
        src/is_functions/ft_isalpha.c		\
        src/is_functions/ft_isascii.c		\
        src/is_functions/ft_isdigit.c		\
        src/is_functions/ft_isprint.c		\
		src/is_functions/ft_str_isnum.c		\
        src/mem_functions/ft_bzero.c		\
        src/mem_functions/ft_calloc.c		\
    	src/mem_functions/ft_memchr.c		\
        src/mem_functions/ft_memcmp.c		\
        src/mem_functions/ft_memcpy.c		\
        src/mem_functions/ft_memmove.c		\
        src/mem_functions/ft_memset.c		\
		src/num_functions/ft_atoi.c			\
		src/num_functions/ft_atol.c			\
		src/num_functions/ft_itoa.c			\
		src/num_functions/ft_hexatoi.c		\
		src/num_functions/ft_power.c		\
		src/put_functions/ft_putchar_fd.c	\
		src/put_functions/ft_putstr_fd.c	\
		src/put_functions/ft_putendl_fd.c	\
		src/put_functions/ft_putnbr_fd.c	\
        src/str_functions/ft_strchr.c		\
        src/str_functions/ft_strdup.c		\
        src/str_functions/ft_until_strdup.c	\
        src/str_functions/ft_strlcat.c		\
        src/str_functions/ft_strlcpy.c		\
        src/str_functions/ft_strlen.c		\
        src/str_functions/ft_strncmp.c		\
        src/str_functions/ft_strnstr.c		\
        src/str_functions/ft_strrchr.c		\
        src/str_functions/ft_tolower.c		\
		src/str_functions/ft_toupper.c		\
		src/str_functions/ft_substr.c		\
		src/str_functions/ft_strjoin.c		\
		src/str_functions/ft_strtrim.c		\
		src/str_functions/ft_strinsert.c	\
		src/str_functions/ft_split.c		\
		src/str_functions/ft_strmapi.c		\
		src/str_functions/ft_striteri.c		\
		src/str_functions/ft_strlen_until.c	\
		src/str_functions/ft_borderchar.c	\
		src/str_functions/ft_deletechar.c	\
		src/get_next_line.c					\
		src/printf_lib/ft_printf.c			\
		src/printf_lib/conversions.c		\
		src/printf_lib/hexptrcase.c			\
		src/printf_lib/utils.c				\

OBJS = ${SRCS:.c=.o}

INCS = -I ./include

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

.c.o:
	@ cc ${CFLAGS} ${INCS} -c $< -o $@

${NAME}: ${OBJS}
	@ ar -rcs ${NAME} ${OBJS}
	@ echo "${GREEN} -=- LIBFT SUCCESSFUL COMPILED -=-${NOCOLOR}"

clean:	
	@ rm -f ${OBJS}
	@ echo "${RED}-=- LIBFT CLEANED -=-${NOCOLOR}"

fclean: clean
	@ rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re