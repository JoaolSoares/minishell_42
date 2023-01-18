/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 00:48:17 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/12 22:16:10 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s1 + i) != *(unsigned char *)(s2 + i))
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
		++i;
	}
	return (0);
}

/*
#include <string.h>
#include <stdio.h>
int main(void)
{
	char *str1 = "Hello World";
	char *str2 = "Hello mundo";
	int i = 0;
	
	while (i <= 13)
	{
		printf("\n======= teste %i =======\n", i);
		printf("esperado: %d\n", memcmp(str1, str2, i));
		printf("resultad: %d\n", ft_memcmp(str1, str2, i));
		i++;
	}

	
	return 0;
}
*/