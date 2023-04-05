/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:39:48 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/04/04 21:08:34 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*cut_command(char **command)
{
	char	*cut_str;
	char	*temp;
	int		i;

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

static void	first_child(t_pipes_data *pipe, char **command, \
t_lists *lists, int *ret_val)
{
	pid_t	pid;

	pid = child_process();
	if (pid < 0)
		exit (330);
	if (pid == 0)
	{
		dup2(pipe->pipefd[0][1], STDOUT_FILENO);
		close_pipes(pipe->pipefd, pipe->num_pipes, 1);
		identify_exec(ft_split(cut_command(command), 4, 1), lists, ret_val);
		free_split(command);
		free(pipe);
		free_exit(lists, command, 0);
		exit(331);
	}
	waitpid(1, NULL, 0);
}

static void	middle_child(t_pipes_data *pipe, char **command, \
t_lists *lists, int *ret_val)
{
	pid_t	pid;

	pid = child_process();
	if (pid < 0)
		exit (440);
	if (pid == 0)
	{
		dup2(pipe->pipefd[pipe->index][0], STDIN_FILENO);
		dup2(pipe->pipefd[pipe->index + 1][1], STDOUT_FILENO);
		close_pipes(pipe->pipefd, pipe->num_pipes, 0);
		identify_exec(ft_split(cut_command(command), 4, 1), lists, ret_val);
		free(pipe);
		free_split(command);
		free_exit(lists, command, 0);
		exit(441);
	}
	waitpid(1, NULL, 0);
}

static void	final_child(t_pipes_data *pipe, char **command, \
t_lists *lists, int *ret_val)
{
	pid_t	pid;

	pid = child_process();
	if (pid < 0)
		exit (550);
	if (pid == 0)
	{
		dup2(pipe->pipefd[pipe->index][0], STDIN_FILENO);
		close_pipes(pipe->pipefd, pipe->num_pipes, 1);
		identify_exec(ft_split(cut_command(command), 4, 1), lists, ret_val);
		free_split(command);
		free(pipe);
		free_exit(lists, command, 0);
		exit(551);
	}
	waitpid(1, NULL, 0);
}

void	call_childs(t_pipes_data *pipe, t_lists *lists, \
char **command, int *ret_val)
{
	char	**cmd_rest;
	char	**aux_cmd;
	int		i;
	int		pipe_position;

	pipe->index = 0;
	first_child(pipe, command, lists, ret_val);
	i = 0;
	while (ft_strncmp(command[i], "|", 2))
		i++;
	cmd_rest = str_rest(0, i, command);
	free_split(command);
	pipe_position = pipe->num_pipes;
	while (pipe_position > 1)
	{
		middle_child(pipe, cmd_rest, lists, ret_val);
		i = 0;
		while (ft_strncmp(cmd_rest[i], "|", 2))
			i++;
		aux_cmd = ft_mtxdup(cmd_rest);
		free_split(cmd_rest);
		cmd_rest = str_rest(0, i, aux_cmd);
		free_split(aux_cmd);
		pipe->index++;
		pipe_position--;
	}
	final_child(pipe, cmd_rest, lists, ret_val);
	free_split(cmd_rest);
}
