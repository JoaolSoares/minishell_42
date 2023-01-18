/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:09:40 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/01/18 19:54:45 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
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

void	exec_command(char *command, char **envp)
{
	char	**cmd;
	char	**possible_paths;
	char	*path;
	int		i;

	possible_paths = find_paths(envp);
	ft_strlcpy(command, command, ft_strlen(command));
	cmd = ft_split(command, ' ');

	i = -1;
	while(possible_paths[++i])
	{
		path = ft_strjoin(ft_strjoin(possible_paths[i], "/"), cmd[0]);
		execve(path, cmd, envp);
		free(path);
	}
	ft_printf("%s: Command Not Found\n", cmd[0]);
	free_split(cmd);	
	free(possible_paths);
}