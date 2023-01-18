/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexatoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 04:22:17 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/12 22:16:24 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	ft_find(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (!str[i])
		return (-1);
	return (i);
}

long int	ft_hexatoi(char *str_hexa)
{
	char		*order;
	int			size;
	long int	res;
	int			i;

	order = 0;
	size = 0;
	while (str_hexa[size])
	{
		if (str_hexa[size] >= 'a' && 'z' >= str_hexa[size]
			&& !order)
			order = "123456789abcdef\0";
		else if (str_hexa[size] >= 'A' && 'Z' >= str_hexa[size]
			&& !order)
			order = "123456789ABCDEF\0";
		size++;
	}
	if (!order)
		order = "123456789ABCDEF\0";
	i = 0;
	res = 0;
	while (size >= 0)
		res += (ft_find(order, str_hexa[--size]) + 1) * (ft_power(16, i++));
	return (res);
}
