/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:17:43 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/04/05 15:02:27 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**str_rest(int delete, int size, char **cmd)
{
	char	*aux_str;
	char	*temp;
	int		i;

	i = 0;
	while (i >= delete && i <= delete + size)
		i++;
	if (!cmd[i])
		return (NULL);
	aux_str = ft_strdup(cmd[i]);
	while (cmd[++i])
	{
		if (i < delete || i > delete + size)
		{
			temp = ft_strdup(aux_str);
			free(aux_str);
			aux_str = ft_strjoin(ft_strjoin(temp, "\4"), cmd[i]);
		}
	}
	return (ft_split(aux_str, 4, 1));
}

static int	open_files(char **cmd, int *i)
{
	int	fd;

	while (cmd[++*i])
	{
		if (!ft_strncmp(cmd[*i], ">", 2))
			fd = open(cmd[*i + 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (!ft_strncmp(cmd[*i], ">>", 3))
			fd = open(cmd[*i + 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (!ft_strncmp(cmd[*i], ">", 2) || !ft_strncmp(cmd[*i], ">>", 3))
			break ;
	}
	return (fd);
}

void	redirect_output(char **cmd, t_lists *lists, int *ret_val)
{
	int		i;
	int		fd;
	int		pid;
	char	**cmd_rest;

	pid = child_process();
	if (pid == 0)
	{
		i = -1;
		fd = open_files(cmd, &i);
		dup2(fd, STDOUT_FILENO);
		if (!ft_strncmp(cmd[0], ">", 2) || !ft_strncmp(cmd[0], ">>", 3))
			cmd_rest = NULL;
		else
			cmd_rest = str_rest(i, 2, cmd);
		free_split(cmd);
		identify_exec(cmd_rest, lists, ret_val);
		free_exit(lists, cmd, 0);
		close(fd);
		exit(0);
	}
	wait(NULL);
	free_split(cmd);
}
