/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 03:26:28 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/11/07 22:00:54 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_atoi(const char *nptr)
{
	int	is_neg;
	int	i;
	int	n;

	is_neg = 1;
	i = 0;
	if (!nptr)
		return (0);
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-')
		is_neg = -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		++i;
	n = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = (n * 10) + nptr[i] - '0';
		++i;
	}
	return (n * is_neg);
}

/*
#include <stdio.h>
#include <stdlib.h>
int main (void)
{
	char *n = "123";
	
	printf("esperado: %i\n", atoi(n));
	printf("resultad: %i\n", ft_atoi(n));

	return 0;
}
*/