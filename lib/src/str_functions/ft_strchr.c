/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:32:05 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/12 22:17:00 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		++s;
	}
	if (!(*s) && !c)
		return ((char *)s);
	return (0);
}

/*
#include <string.h>
#include <stdio.h>
int main(void)
{
	char *str = "Hello World";
	int c = 'a';
	
	while (c <= 'z')
	{
		printf("\n======= teste %c =======\n", c);
		printf("esperado: %s\n", strchr(str, c));
		printf("resultad: %s\n", ft_strchr(str, c));
		c++;
	}
	
	return 0;
}
*/