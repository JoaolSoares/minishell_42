/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:09:40 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/03/01 22:53:13 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

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

static char	**absolut_path(char **path)
{
	char	**command;
	char	*temp;

	temp = ft_strdup(ft_strrchr(path[0], '/'));
	free_split(path);
	command = ft_split(temp, ' ');
	free(temp);
	return (command);
}

void	execve_command(char **command, char **envp)
{
	char	**possible_paths;
	char	*temp;
	char	*path;
	int		i;

	temp = ft_strdup(command[0]);
	if (ft_strchr(command[0], '/'))
		command = absolut_path(command);
	possible_paths = find_paths(envp);
	i = -1;
	while (possible_paths[++i])
	{
		path = ft_strjoin(ft_strjoin(possible_paths[i], "/"), command[0]);
		execve(path, command, envp);
		free(path);
	}
	ft_printf("%s: Command Not Found\n", temp);
	free_split(command);
	free(possible_paths);
	free(temp);
	exit (30);
}
