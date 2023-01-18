/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 00:19:10 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/12 22:17:15 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		++i;
	return (i);
}

/*
#include <string.h>
#include <stdio.h>
int main(void)
{
	char *s = "Hello World";
	printf("Esperado: %ld\n", strlen(s));
	printf("Resultad: %ld\n", ft_strlen(s));
	
	return 0;
}
*/