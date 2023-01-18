/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexptrcase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 03:09:13 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/12 22:15:04 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	ft_putptr(unsigned long int n)
{
	int	ret;

	ret = 0;
	if (n >= 16)
	{
		ret += ft_putptr(n / 16);
		ret += ft_putptr(n % 16);
	}
	else if (n <= 9)
		ret += ft_putchar(n + '0');
	else
		ret += ft_putchar(n - 10 + 'a');
	return (ret);
}

int	ft_pointercase(va_list ap)
{
	unsigned long int	n;
	int					ret;

	n = va_arg(ap, unsigned long int);
	ret = 0;
	if (n == 0)
		return (write(1, "(nil)", 5));
	else
	{
		ret += write(1, "0x", 2);
		ret += ft_putptr(n);
	}
	return (ret);
}

int	ft_hexcase(unsigned long int n, char c)
{
	int	ret;

	ret = 0;
	if (n >= 16)
	{
		ret += ft_hexcase(n / 16, c);
		ret += ft_hexcase(n % 16, c);
	}
	else if (n <= 9)
		ret += ft_putchar(n + '0');
	else
		ret += ft_putchar(n - 10 + (c - 23));
	return (ret);
}
