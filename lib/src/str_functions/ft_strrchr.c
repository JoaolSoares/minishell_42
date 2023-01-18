/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 00:05:02 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/12 22:17:27 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i));
		--i;
	}
	return (0);
}

/*
#include "ft_strlen.c"
#include <string.h>
#include <stdio.h>
int main(void)
{
	char *str = "Hello World";
	int c = 'a';
	
	while (c <= 'z')
	{
		printf("\n======= teste %c =======\n", c);
		printf("esperado: %s\n", strrchr(str, c));
		printf("resultad: %s\n", ft_strrchr(str, c));
		c++;
	}
	
	return 0;
}
*/