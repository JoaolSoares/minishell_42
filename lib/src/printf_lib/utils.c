/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 03:26:11 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/12 22:15:06 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_numlen(int n)
{
	long int	i;

	i = 1;
	if (n == -2147483648)
		return (11);
	else if (n < 0)
	{
		n *= -1;
		i++;
	}
	while ((n / 10) > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_uputnbr(unsigned int n)
{
	unsigned int	num;

	if ((n / 10) > 0)
	{
		ft_uputnbr(n / 10);
	}
	num = (n % 10) + '0';
	write(1, &num, 1);
}

int	ft_unumlen(unsigned int n)
{
	unsigned int	i;

	i = 1;
	while ((n / 10) > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
