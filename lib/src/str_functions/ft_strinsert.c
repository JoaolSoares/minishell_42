/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:53:14 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/03/10 18:57:12 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strinsert(char *str, char *insert, int index_insert)
{
	char	*dest;
	int		i;
	int		j;
	int		k;

	dest = malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(insert) + 1));
	i = 0;
	k = 0;
	while (i < index_insert)
		dest[i++] = str[k++];
	j = 0;
	while (insert[j])
		dest[i++] = insert[j++];
	while (str[k])
		dest[i++] = str[k++];
	dest[i] = 0;
	return (dest);
}

// int main(void)
// {
// 	char *str = ft_strdup("echo '    '");
// 	char *insert = "joaolsoares";

// 	char *dest = ft_strinsert(str, insert, 9);
// 	ft_printf(dest);

// 	free(str);
// 	free(dest);
// 	return (0);
// }