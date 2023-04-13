/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:39:48 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/04/12 20:25:22 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*cut_command(char **command)
{
	char	*cut_str;
	char	*temp;
	int		i;

	if (!ft_strncmp(command[0], "|", 2))
		return (NULL);
	i = 1;
	cut_str = ft_strdup(command[0]);
	while (command[i] && ft_strncmp(command[i], "|", 2))
	{
		temp = ft_strdup(cut_str);
		free(cut_str);
		cut_str = ft_strjoin(ft_strjoin(temp, "\4"), command[i]);
		i++;
	}
	return (cut_str);
}

void	first_child(t_pipes_data *pipe, char **command, \
t_lists *lists, int *ret_val)
{
	pid_t	pid;
	char	**alone_cmd;

	pid = child_process();
	if (pid < 0)
		exit (330);
	if (pid == 0)
	{
		dup2(pipe->pipefd[0][1], STDOUT_FILENO);
		close_pipes(pipe->pipefd, pipe->num_pipes, 1);
		free(pipe);
		alone_cmd = ft_split(cut_command(command), 4, 1);
		free_split(command);
		identify_exec(alone_cmd, lists, ret_val);
		free_exit(lists, command, 0);
		exit(331);
	}
}

void	middle_child(t_pipes_data *pipe, char **command, \
t_lists *lists, int *ret_val)
{
	pid_t	pid;
	char	**alone_cmd;

	pid = child_process();
	if (pid < 0)
		exit (440);
	if (pid == 0)
	{
		dup2(pipe->pipefd[pipe->index][0], STDIN_FILENO);
		dup2(pipe->pipefd[pipe->index + 1][1], STDOUT_FILENO);
		close_pipes(pipe->pipefd, pipe->num_pipes, 0);
		free(pipe);
		alone_cmd = ft_split(cut_command(command), 4, 1);
		free_split(command);
		identify_exec(alone_cmd, lists, ret_val);
		free_exit(lists, command, 0);
		exit(441);
	}
}

void	final_child(t_pipes_data *struct_pipe, char **command, \
t_lists *lists, int *ret_val)
{
	pid_t	pid;
	char	**alone_cmd;
	int		pipe_ret_fd[2];

	if (pipe(pipe_ret_fd) < 0)
		exit (1);
	pid = child_process();
	if (pid < 0)
		exit (550);
	if (pid == 0)
	{
		close(pipe_ret_fd[0]);
		dup2(struct_pipe->pipefd[struct_pipe->index][0], STDIN_FILENO);
		close_pipes(struct_pipe->pipefd, struct_pipe->num_pipes, 1);
		free(struct_pipe);
		alone_cmd = ft_split(cut_command(command), 4, 1);
		free_split(command);
		// write(pipe_ret_fd[1], ret_val, sizeof(int));
		identify_exec(alone_cmd, lists, ret_val);
		write(pipe_ret_fd[1], ret_val, sizeof(int));	//trava quando da certo o commando
		close(pipe_ret_fd[1]);
		free_exit(lists, command, 0);
		exit(551);
	}
	close(pipe_ret_fd[1]);
	read(pipe_ret_fd[0], ret_val, sizeof(int));
	close(pipe_ret_fd[0]);
}
