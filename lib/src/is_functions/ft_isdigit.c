/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:35:49 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/12 22:15:20 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	return (0);
}

/*
#include <ctype.h>
#include <stdio.h>
int main(void)
{
	char c = '1';
	printf("Esperado: %d\n", isdigit(c));
	printf("Resultad: %d\n", ft_isdigit(c));
	
	return 0;
}
*/