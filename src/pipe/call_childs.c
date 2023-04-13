/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_childs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:20:41 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/04/12 17:28:03 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	find_pipe(char **str)
{
	int		i;

	i = 0;
	while (ft_strncmp(str[i], "|", 2))
		i++;
	return (i);
}

void	call_childs(t_pipes_data *pipe, t_lists *lists, \
char **command, int *ret_val)
{
	char	**cmd_rest;
	char	**aux_cmd;
	int		i;
	int		pipe_position;

	first_child(pipe, command, lists, ret_val);
	i = find_pipe(command);
	cmd_rest = str_rest(0, i, command);
	free_split(command);
	if (!cmd_rest)
		return ;
	pipe_position = pipe->num_pipes;
	while (pipe_position > 1)
	{
		middle_child(pipe, cmd_rest, lists, ret_val);
		i = find_pipe(cmd_rest);
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
