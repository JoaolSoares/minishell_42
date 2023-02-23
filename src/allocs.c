/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:03:20 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/02/23 19:34:37 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	free_split(char **split, int opt)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	if (opt == 1)
		free(split);
}

char **envp_copy(char **envp)
{
	int		i;
	char	**copy;
	
	i = -1;
	while (envp[++i]) ;
	copy = malloc(sizeof(char *) * (i + 1));
	
	i = -1;
	while (envp[++i])
		copy[i] = ft_strdup(envp[i]);
	copy[i] = 0;

	return (copy);
}

// void	envp_malloc(char *envp[])
// {
// 	char	*copy;
// 	int		i;

// 	i = -1;
// 	while (envp[++i])
// 	{
// 		copy = ft_strdup(envp[i]);
// 		envp[i] = ft_calloc(sizeof(char), ft_strlen(envp[i]) + 1);
// 		ft_strlcpy(envp[i], copy, ft_strlen(copy) + 1);
// 		free(copy);
// 	}
// }
