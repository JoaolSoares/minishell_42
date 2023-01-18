/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:08:29 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/12 22:17:25 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	i;
	size_t	l_size;

	i = 0;
	l_size = ft_strlen(little);
	if (!little[i])
		return ((char *)big);
	while (big[i] && i < len)
	{
		if (!ft_strncmp(big + i, little, l_size) && (l_size + i <= len))
			return ((char *)(big + i));
		++i;
	}
	return (0);
}

/*
#include <bsd/string.h>
#include <stdio.h>
#include "ft_strlen.c"
#include "ft_strncmp.c"
int main(void)
{
	char *big = "aaabcabcd";
	char *little = "abcd";
	int n = 9;
		printf("\n======= teste %i =======\n", n);
		printf("esperado: %s\n", strnstr(big, little, n));
		printf("resultad: %s\n", ft_strnstr(big, little, n));
	
	return 0;
}
*/