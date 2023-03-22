/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:56:39 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/03/21 15:18:55 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char **fodace(int start, int end, char **cmd)
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
	return (ft_split(aux_str, 4, 1));
}

void	redirect_input(char **cmd, t_lists *lists, int *ret_val)
{
	int		i;
	int		fd;
	int		pid;
	char	**cmd_rest;

	pid = child_process();
	if (pid == 0)
	{
		i = -1;
		while (ft_strncmp(cmd[++i], "<", 2)) ; 
		fd = open(cmd[i + 1], O_RDONLY);
		if (fd < 0)
		{
			ft_printf("minishell: %s: No such file or directory\n", cmd[i + 1]);
			free_exit(lists, cmd);
			exit(1);
		}
		dup2(fd, STDIN_FILENO);
		if (cmd[i + 2])
			cmd_rest = fodace(i + 2, 1000, cmd);
		else
			cmd_rest = fodace(0, i - 1, cmd);
		// for (int i = 0; cmd_rest[i]; i++)
		// 	ft_printf("input[%i]: %s\n", i, cmd_rest[i]);
		identify_exec(cmd_rest, lists, ret_val);
		free_exit(lists, cmd);
		exit(0);
	}
	wait(NULL);
}
