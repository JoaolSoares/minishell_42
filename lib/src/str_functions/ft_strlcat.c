/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 23:33:35 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/12 22:17:08 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_size;
	size_t	i;
	size_t	j;

	dest_size = ft_strlen(dest);
	i = dest_size;
	j = 0;
	if (dest_size < size - 1 && size > 0)
	{
		while (src[j] && dest_size + j < size - 1)
			dest[i++] = src[j++];
		dest[i] = '\0';
	}
	if (dest_size > size)
		dest_size = size;
	return (ft_strlen(src) + dest_size);
}

/*
#include "ft_strlen.c"  //TIRAR ESSA COISA
#include <bsd/string.h>
#include <stdio.h>
int main(void)
{
	char *dest;
	memset(dest, 'r', 15);
	char * src = "lorem ipsum dolor sit amet";
	
	int size = 5;

	printf("\n======= teste %i =======\n", size);
	
	printf("Resultad: %ld\n", ft_strlcat(dest, src, size));
	printf("dest: %s\n src: %s\n", dest, src);


	return 0;
}
*/