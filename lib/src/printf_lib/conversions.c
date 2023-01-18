/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 00:35:12 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/12 22:14:34 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	ft_charcase(va_list ap)
{
	ft_putchar((char)va_arg(ap, int));
	return (1);
}

static int	ft_strcase(va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

static int	ft_intdigitcase(va_list ap)
{
	int	num;

	num = va_arg(ap, int);
	ft_putnbr_fd(num, 1);
	return (ft_numlen(num));
}

static int	ft_unsignedintcase(va_list ap)
{
	unsigned int	num;

	num = va_arg(ap, unsigned int);
	ft_uputnbr(num);
	return (ft_unumlen(num));
}

/* -------------- TYPE CONVERSION ---------------- */

int	ft_type_conversion(va_list ap, char c)
{
	int	ret;

	ret = 0;
	if (c == 'c')
		ret = ft_charcase(ap);
	else if (c == 's')
		ret = ft_strcase(ap);
	else if (c == 'p')
		ret = ft_pointercase(ap);
	else if (c == 'd' || c == 'i')
		ret = ft_intdigitcase(ap);
	else if (c == 'u')
		ret = ft_unsignedintcase(ap);
	else if (c == 'x' || c == 'X')
		ret += ft_hexcase(va_arg(ap, unsigned int), c);
	else if (c == '%')
		ret += write(1, &c, 1);
	return (ret);
}
