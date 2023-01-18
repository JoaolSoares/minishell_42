/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:16:03 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/12 22:16:58 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static char	*ft_wordcreate(char *dest, char const *s, int index, int len)
{
	int		j;

	j = 0;
	while (len > 0)
	{
		dest[j] = s[index - len];
		++j;
		--len;
	}
	dest[j] = 0;
	return (dest);
}

static char
	**ft_splitwords(char **split, char const *s, char c, int words_count)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	while (s[i] && j < words_count)
	{
		len = 0;
		while (s[i] && s[i] == c)
			++i;
		while (s[i] && s[i] != c)
		{
			++i;
			++len;
		}
		split[j] = (char *)malloc(sizeof(char) * (len + 1));
		if (!split[j])
			return (0);
		ft_wordcreate(split[j], s, i, len);
		++j;
	}
	split[j] = 0;
	return (split);
}

static int	ft_wordscount(char const *s, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			++count;
		else if (s[i] != c && s[i - 1] == c)
			++count;
		++i;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		words_count;

	if (!s)
		return (0);
	words_count = ft_wordscount(s, c);
	split = (char **)malloc(sizeof(s) * (words_count + 1));
	if (!split)
		return (0);
	ft_splitwords(split, s, c, words_count);
	return (split);
}

/*
#include <stdio.h>
int main(void)
{
	char *str = "  suco addes  de maca  "; 
	char c = ' ';
	int i = 0;
	
	char **array = ft_split(str, c);
	
	while (i <= ft_wordscount(str, c))
	{
		printf("array[%i] = %s\n", i, array[i]);
		++i;
	}
	
	free(array[0]);
	free(array[1]);
	free(array[2]);
	free(array[3]);
	free(array);

	return 0;
}
*/