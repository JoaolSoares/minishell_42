/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 21:55:50 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/03/09 15:37:35 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

//	INCLUDES	
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

//	DEFINES
# define BUFFER_SIZE 42

/* ------------ FUNCTIONS ------------ */
//	IS_FUNCTIONS
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_str_isnum(char *str);

//	MEM_FUNCTIONS
void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);

//	NUM_FUNCTIONS
int			ft_atoi(const char *nptr);
long int	ft_atol(const char *nptr);
char		*ft_itoa(int n);
long int	ft_hexatoi(char *str_hexa);
long int	ft_power(int nb, int power);

//	STR_FUNCTIONS
int			ft_toupper(int c);
int			ft_tolower(int c);

size_t		ft_strlen(const char *s);
size_t		ft_strlen_until(const char *s, char c);

size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlcat(char *dest, const char *src, size_t size);

char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strdup(const char *src);
char		*ft_until_strdup(const char *s, size_t index);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char *s, char c, int opt);
char		*ft_strinsert(char *str, char *insert, int index_insert);

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));

char		*ft_borderchar(char *str, char border);
char		*ft_deletechar(char *str, size_t index);

//	PUT_FUNCTIONS
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

//	GNL
char		*get_next_line(int fd);

//	PRINTF
int			ft_printf(const char *str, ...);
int			ft_type_conversion(va_list ap, char c);

int			ft_numlen(int n);
int			ft_unumlen(unsigned int n);
int			ft_putchar(char c);
void		ft_uputnbr(unsigned int n);

int			ft_pointercase(va_list ap);
int			ft_hexcase(unsigned long int n, char c);

#endif