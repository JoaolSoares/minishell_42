/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_borderchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 23:37:05 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/26 23:40:47 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_borderchar(char *str, char border)
{
	char	*border_str;
	int		i;

	if (str[0] == border && str[ft_strlen(str) - 1] == border)
		return (str);
	border_str = malloc(sizeof(char) * ft_strlen(str) + 3);
	if (!border_str)
		return (0);
	i = 0;
	border_str[i++] = border;
	while (str[i - 1] && i < (int)ft_strlen(str) + 2)
	{
		border_str[i] = str[i - 1];
		i++;
	}
	border_str[i] = border;
	border_str[i + 1] = 0;
	return (border_str);
}
