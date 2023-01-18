/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 00:35:14 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/12 22:17:02 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strdup(const char *s)
{
	int		s_size;
	char	*new_s;

	s_size = ft_strlen(s);
	new_s = (char *)malloc(sizeof(char) * (s_size + 1));
	if (!new_s)
		return (0);
	while (s_size >= 0)
	{
		new_s[s_size] = s[s_size];
		--s_size;
	}
	return (new_s);
}

/*
#include <stdio.h>
#include "ft_strlen.c"
#include <string.h>

int main(void)
{
	char *str = "hello mundo";
	char *strdup = ft_strdup(str);
	
	printf("\nStrOri: %s\n Pointer: %p\n", str, str);
	printf("StrDup: %s\n Pointer: %p\n", strdup, strdup);

	free(strdup);
	return 0;
}
*/