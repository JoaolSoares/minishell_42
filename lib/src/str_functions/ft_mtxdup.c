/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtxdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:37:14 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/04/12 21:48:07 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	**ft_mtxdup(char **mtx)
{
	int		i;
	char	**new_mtx;

	i = 0;
	while (mtx[i])
		i++;
	new_mtx = malloc(sizeof(char *) * (i + 1));
	if (!new_mtx)
		return (0);
	i = -1;
	while (mtx[++i])
		new_mtx[i] = ft_strdup(mtx[i]);
	new_mtx[i] = NULL;
	return (new_mtx);
}

// int main(void)
// {
// 	char	**mtx;
// 	char	**dup;

// 	mtx = ft_split("hello world", ' ', 0);
// 	dup = ft_mtxdup(mtx);
// 	free_split(mtx);

// 	for(int i = 0; dup[i]; i++)
// 		ft_printf("[%i] = %s\n", i, dup[i]);

// 	free_split(dup);
// 	return (0);
// }