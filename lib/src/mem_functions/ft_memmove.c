/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 00:31:52 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/12 22:16:14 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	if (dest == src)
		return (dest);
	if (s < d)
	{
		while (n--)
			*(d + n) = *(s + n);
		return (dest);
	}
	while (n--)
		*d++ = *s++;
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	char dst[] = "zzzzz";
	char src[] = "xxxxx";
	printf("        src: %s\n", src);

	printf("dest before: %s\n", dst);
	ft_memmove(dst, src, 2);
	printf(" dest after: %s\n", dst);
	
	return 0;
}
*/