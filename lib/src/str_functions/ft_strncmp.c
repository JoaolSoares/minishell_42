/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 00:10:06 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/12 22:17:23 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
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
	int i = -10;
	
	while (i <= 20)
	{
		printf("\n======= teste %i =======\n", i);
		printf("esperado: %d\n", strncmp(str1, str2, i));
		printf("resultad: %d\n", ft_strncmp(str1, str2, i));
		i++;
	}

	
	return 0;
}
*/