/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 01:50:32 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/12 22:16:12 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*u_dst;
	unsigned char	*u_src;
	size_t			i;

	u_dst = (unsigned char *)dest;
	u_src = (unsigned char *)src;
	i = 0;
	while (i < n && dest)
	{
		u_dst[i] = u_src[i];
		++i;
	}
	return (dest);
}

/*
#include <stdio.h>
int main(void)
{
	char dst[100];
	char *src = "Hello World";
	printf("        src: %s\n", src);

	printf("dest before: %s\n", dst);
	ft_memcpy(dst, src, 10);
	printf(" dest after: %s\n", dst);
	
	return 0;
}
*/