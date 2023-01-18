/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 00:46:34 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/26 23:51:55 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static size_t	ft_findstart(char const *s, char const *set)
{
	size_t	start;
	size_t	i;

	start = 0;
	while (s[start])
	{
		i = 0;
		while (s[start] != set[i] && set[i])
			++i;
		if (i != ft_strlen(set))
			++start;
		else
			break ;
	}
	return (start);
}

static size_t	ft_findend(char const *s, char const *set, size_t start)
{
	size_t	end;
	size_t	i;

	end = ft_strlen(s);
	while (end > start)
	{
		i = 0;
		while (s[end - 1] != set[i] && set[i])
			++i;
		if (i != ft_strlen(set))
			--end;
		else
			break ;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = ft_findstart(s1, set);
	end = ft_findend(s1, set, start);
	str = ft_substr(s1, start, end - start);
	return (str);
}

/* 
#include <stdio.h>
int main(void)
{
	char *s1 = "lorem ipsum dolor sit amet";
	char *set = "te"; // ello world
	printf("  s1: %s\n  set: %s\ntrim:\n%s\n", s1, set, ft_strtrim(s1, set));
	return 0;
}
 */