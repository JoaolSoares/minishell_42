/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 23:43:44 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/04/18 22:27:17 by jlucas-s         ###   ########.fr       */
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

	s_pipe = malloc(sizeof(t_pipes_data));
	s_pipe->num_pipes = count_pipes(command);
	s_pipe->pipefd = open_pipes(s_pipe->num_pipes);
	s_pipe->index = 0;
	call_childs(s_pipe, lists, command, ret_val);
	free(s_pipe);
}
