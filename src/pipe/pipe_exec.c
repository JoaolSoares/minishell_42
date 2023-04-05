/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 23:43:44 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/04/05 02:27:21 by jlucas-s         ###   ########.fr       */
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
	t_pipes_data	*pipe;

	pipe = malloc(sizeof(t_pipes_data));
	pipe->num_pipes = count_pipes(command);
	pipe->pipefd = open_pipes(pipe->num_pipes);
	call_childs(pipe, lists, command, ret_val);
	wait(NULL);
	close_pipes(pipe->pipefd, pipe->num_pipes, 1);
	free(pipe);
}
