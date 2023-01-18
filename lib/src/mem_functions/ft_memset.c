/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 22:08:28 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/12 22:16:16 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*u_s;
	size_t			i;

	u_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		u_s[i] = c;
		++i;
	}
	return (u_s);
}

/*
#include <stdio.h>
int main(void)
{
	char s[] = "Hello World";
	
	printf("before: %s\n", s);
	ft_memset(s, 'H', 5);
	printf("after: %s\n", s);
	
	return 0;
}
*/