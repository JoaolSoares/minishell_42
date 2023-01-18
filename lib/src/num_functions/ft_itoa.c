/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 02:40:52 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/12 22:16:27 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static void	ft_rev_str(char *str)
{
	int		len;
	int		i;
	char	temp;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
		++i;
	}
}

char	*ft_itoa(int n)
{
	char	*num;
	int		is_neg;
	size_t	i;

	if (!n)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	is_neg = (n < 0);
	if (is_neg)
		n = n * (-1);
	num = ft_calloc(12, sizeof(char));
	if (!num)
		return (0);
	i = 0;
	while (n != 0)
	{
		num[i++] = (n % 10) + '0';
		n = (n / 10);
	}
	if (is_neg)
		num[i] = '-';
	ft_rev_str(num);
	return (num);
}

/*
#include "ft_strlen.c"
#include <stdio.h>
int main(void)
{
	char *num = ft_itoa(10);
	printf("%s\n", num);
	free(num);
	return 0;
}
*/