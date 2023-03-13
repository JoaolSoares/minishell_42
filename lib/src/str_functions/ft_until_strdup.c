/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_until_strdup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:39:14 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/03/09 15:39:44 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strdup_until(const char *s, size_t index)
{
	char	*new_s;

	if (index > ft_strlen(s))
		index = ft_strlen(s);
	new_s = (char *)malloc(sizeof(char) * (index) + 1);
	if (!new_s)
		return (0);
	new_s[index] = 0;
	while (--index)
		new_s[index] = s[index];
	new_s[index] = s[index];
	return (new_s);
}
