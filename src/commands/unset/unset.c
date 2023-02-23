/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:34:27 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/02/23 19:51:36 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	unset(char *command, char **envp)
{
	int		i;
	char	*unseted;
	char	**copy;

	i = 5;
	while (command[++i] == ' ') ;
	unseted = ft_strdup(command + i);

	/// while de verifi9car se a variavel existe msm

	i = -1;
	while (envp[++i]) ;
	copy = malloc(sizeof(char *) * (i + 1));

	i = -1;
	while(envp[++i])
		copy[i] = ft_strdup(envp[i]);
	copy[i] = 0;

	free_split(envp, 1);
	envp = malloc(sizeof(char *) * (i + 1));

	i = -1;
	while(copy[++i])
		envp[i] = ft_strdup(copy[i]);
	envp[i] = 0;

	// i = -1;
	// while (envp[++i])
	// 	ft_printf("%s\n", envp[i]);
	
	free_split(copy, 1);
	free(unseted);
	return (0);
}
