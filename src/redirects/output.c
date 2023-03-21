/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:17:43 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/03/20 21:55:30 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char *fodace(int start, int end, char **cmd)
{
	char	*aux_str;
	char	*temp;

	aux_str = ft_strdup(cmd[start]);
	while (++start <= end && cmd[start])
	{
		temp = ft_strdup(aux_str);
		free(aux_str);
		aux_str = ft_strjoin(ft_strjoin(temp, "\4"), cmd[start]);
	}
	
	return (aux_str);
}

void	redirect_output(char **cmd, t_lists *lists, int *ret_val)
{
	int		i;
	int		fd;
	int		pid;
	char	*cmd_rest;

	pid = child_process();
	if (pid == 0)
	{
		i = -1;
		while (cmd[++i])
		{
			if (!ft_strncmp(cmd[i], ">", 2))
			{
				fd = open(cmd[i + 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
				break ;
			}
			if (!ft_strncmp(cmd[i], ">>", 3))
			{
				fd = open(cmd[i + 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
				break ;
			}
		}
		dup2(fd, STDOUT_FILENO);
		if (!ft_strncmp(cmd[0], ">", 2) || !ft_strncmp(cmd[i], ">>", 3))
			cmd_rest = NULL;
		else
			cmd_rest = fodace(0, i - 1, cmd);
		identify_exec(cmd_rest, lists, ret_val);
		free(cmd_rest);
		free_exit(lists, cmd);
		exit(0);
	}
	wait(NULL);
}
