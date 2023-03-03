/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:09:40 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/03/03 16:36:29 by jlucas-s         ###   ########.fr       */
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

static int	execve_command(char **command, char **envp)
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
	return (1);
}

static pid_t	child_process(void)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		exit (20);
	return (pid);
}

int	execve_return(char **split_cmd, char **envp)
{
	pid_t	pid;
	int		pipe_fd[2];
	int		return_value;

	if (pipe(pipe_fd) < 0)
		exit (1);
	pid = child_process();
	if (pid == 0)
	{
		close(pipe_fd[0]);
		return_value = execve_command(split_cmd, envp);
		write(pipe_fd[1], &return_value, sizeof(int));
		close(pipe_fd[1]);
		exit(1);
	}
	wait(NULL);
	close(pipe_fd[1]);
	return_value = 0;
	read(pipe_fd[0], &return_value, sizeof(int));
	close(pipe_fd[0]);
	return (return_value);
}
