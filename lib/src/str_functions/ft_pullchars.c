/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pullchars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:18:49 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/03/15 21:04:42 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_pullchars(char *str, size_t index, char final_char)
{
	if (index == ft_strlen(str) - 1)
		str[index] = 4;
	else if (index < ft_strlen(str))
	{
		while (str[++index])
			str[index - 1] = str[index];
		str[index - 1] = final_char;
	}
}
