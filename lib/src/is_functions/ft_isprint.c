/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 00:12:18 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/12 22:15:21 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_isprint(int c)
{
	if (c > 31 && c < 127)
		return (16384);
	return (0);
}

/*
#include <ctype.h>
#include <stdio.h>
int main(void)
{
	char c = 'a';
	printf("Esperado: %d\n", isprint(c));
	printf("Resultad: %d\n", ft_isprint(c));
	
	return 0;
}
*/