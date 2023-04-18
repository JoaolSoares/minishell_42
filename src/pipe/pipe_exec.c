/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 23:43:44 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/04/17 19:05:14 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	count_pipes(char **command)
{
	int	i;
	int	num_pipes;

	i = -1;
	num_pipes = 0;
	while (command[++i])
		if (!ft_strncmp(command[i], "|", 2))
			num_pipes++;
	return (num_pipes);
}

void	pipe_exec(char **command, t_lists *lists, int *ret_val)
{
	t_pipes_data	*s_pipe;
	int				i;

	s_pipe = malloc(sizeof(t_pipes_data));
	s_pipe->num_pipes = count_pipes(command);
	s_pipe->pipefd = open_pipes(s_pipe->num_pipes);
	s_pipe->index = 0;
	if (pipe(s_pipe->ret_pipe) < 0)
		exit(1);
	call_childs(s_pipe, lists, command, ret_val);
	close_pipes(s_pipe->pipefd, s_pipe->num_pipes, 1);
	i = -1;
	while (++i <= s_pipe->num_pipes)
		waitpid(0, NULL, 0);
	// tentar colocar aqui os read
	close(s_pipe->ret_pipe[1]);
	read(s_pipe->ret_pipe[0], ret_val, sizeof(int));
	close(s_pipe->ret_pipe[0]);
	free(s_pipe);
}
