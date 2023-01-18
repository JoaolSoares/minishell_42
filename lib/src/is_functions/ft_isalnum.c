/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:35:44 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/12 22:15:13 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_isalnum(int c)
{
	if (ft_isdigit(c) || ft_isalpha(c))
		return (8);
	return (0);
}

/*
#include <ctype.h>
#include <stdio.h>
int main(void)
{
	char c = 'a';
	printf("Esperado: %d\n", isalnum(c));
	printf("Resultad: %d\n", ft_isalnum(c));
	
	return 0;
}
*/