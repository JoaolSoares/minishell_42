/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 00:25:10 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/12 22:16:07 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (i < n)
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
			return ((void *)(s + i));
		++i;
	}
	return (0);
}

/*
#include <string.h>
#include <stdio.h>
int main(void)
{
	char str[] = "Hello World";
	int c = 'a';
	int n = 11;
	
	while (c <= 'z')
	{
		printf("\n======= teste %c =======\n", c);
		printf("esperado: %s\n", memchr(str, c, n));
		printf("resultad: %s\n", ft_memchr(str, c, n));
		c++;
	}
	
	return 0;
}
*/