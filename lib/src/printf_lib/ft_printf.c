/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 07:08:06 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/12 22:15:02 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		ret;

	va_start(ap, str);
	i = 0;
	ret = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (ft_strchr("cspdiuxX%", str[i + 1]))
				ret += ft_type_conversion(ap, str[++i]);
			else
				ret += write(1, &str[i], 1);
		}
		else
			ret += write(1, &str[i], 1);
		i++;
	}
	va_end(ap);
	return (ret);
}
