/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:09:40 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/03/09 20:33:47 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	**find_paths(char **envp)
{
	int		i;
	char	**paths;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH", 4))
	{
		i++;
		if (!envp[i])
			return(NULL);
	}
	paths = ft_split(envp[i] + 5, ':', 0);
	return (paths);
}

static int	execve_command(char **command, char **envp)
{
	char	**possible_paths;
	char	*temp;
	char	*path;
	int		i;

	temp = ft_strdup(command[0]);
	execve(command[0], command, envp);
	possible_paths = find_paths(envp);
	i = -1;
	while (possible_paths && possible_paths[++i])
	{
		path = ft_strjoin(ft_strjoin(possible_paths[i], "/"), command[0]);
		execve(path, command, envp);
		free(path);
	}
	if (!possible_paths)
		ft_printf("minishell: %s: No such file or directory\n", temp);
	else
		ft_printf("minishell: %s: command not found\n", temp);
	
	free_split(command);
	free_split(envp);
	free(possible_paths);
	free(temp);
	return (127);
}

static char	**env_to_envp(t_node *env)
{
	t_node	*aux;
	int		i;
	char	**envp;

	aux = env;
	i = 0;
	while (aux && ++i)
		aux = aux->next;
	envp = malloc(sizeof(char *) * (i + 1));
	aux = env;
	i = 0;
	while (aux)
	{
		envp[i++] = ft_strdup(aux->content);
		aux = aux->next;
	}
	envp[i] = NULL;
	return(envp);
}

int	execve_return(char **split_cmd, t_node *env)
{
	pid_t	pid;
	int		pipe_fd[2];
	int		return_value;
	char	**envp;

	if (pipe(pipe_fd) < 0)
		exit (1);
	pid = child_process();
	if (pid == 0)
	{
		close(pipe_fd[0]);
		envp = env_to_envp(env);
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
