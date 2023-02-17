/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:09:40 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/02/16 19:04:03 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	**find_paths(char **envp)
{
	int		i;
	char	**paths;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH", 4))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	return (paths);
}

void	execve_command(char **command, char **envp)
{
	char	**possible_paths;
	char	*path;
	int		i;

	possible_paths = find_paths(envp);

	i = -1;
	while(possible_paths[++i])
	{
		path = ft_strjoin(ft_strjoin(possible_paths[i], "/"), command[0]);
		execve(path, command, envp);
		free(path);
	}
	ft_printf("%s: Command Not Found\n", command[0]);
	free_split(command, 1);
	free(possible_paths);
	exit (30);
}
