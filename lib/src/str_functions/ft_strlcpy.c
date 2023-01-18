/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 22:17:05 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/12 22:17:11 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (0);
	if (size > 0)
	{
		while (src[i] && i + 1 < size)
		{
			dst[i] = src[i];
			++i;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

/*
#include "ft_strlen.c" //TIRAR
#include <bsd/string.h>
#include <stdio.h>
int main(void)
{
	char *src = "Hello World";
	char dest[100];
	char dest2[100];
	int size = 1;
	
	printf("esperado: %ld\n", strlcpy(dest, src, size));
	printf("dest: %s\n", dest);
	
	printf("resultad: %ld\n", ft_strlcpy(dest2, src, size));
	printf("dest: %s\n", dest2);
	
	return 0;
}
*/