/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:56:39 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/04/04 22:20:24 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**input(char **cmd, int i, t_lists *lists)
{
	int		fd;
	char	**cmd_rest;

	fd = open(cmd[i + 1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("minishell: %s: No such file or directory\n", cmd[i + 1]);
		free_exit(lists, cmd, 1);
		exit(1);
	}
	dup2(fd, STDIN_FILENO);
	if (cmd[i + 2])
		cmd_rest = str_rest(i, 1, cmd);
	else
		cmd_rest = str_rest(i, 1, cmd);
	close(fd);
	return (cmd_rest);
}

void	heredoc_content(char **cmd, t_lists *lists, int i)
{
	int		fd;
	char	*line;

	fd = open("heredoc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		ft_printf("minishell: %s: No such file or directory\n", cmd[i + 1]);
		free_exit(lists, cmd, 1);
		exit(1);
	}
	line = ft_strdup("");
	while (ft_strncmp(line, cmd[i + 1], ft_strlen(line) + 1))
	{
		free(line);
		line = readline("> ");
		if (!line)
		{
			free(line);
			close(fd);
		}
		if (ft_strncmp(line, cmd[i + 1], ft_strlen(cmd[i + 1])))
			ft_putendl_fd(line, fd);
	}
	close(fd);
	free(line);
}

char	**heredoc_input(char **cmd, int i, t_lists *lists)
{
	int		fd;
	char	**cmd_rest;

	heredoc_content(cmd, lists, i);
	fd = open("heredoc", O_RDONLY);
	dup2(fd, STDIN_FILENO);
	cmd_rest = str_rest(i, 1, cmd);
	close(fd);
	return (cmd_rest);
}

void	identify_input(char **cmd, t_lists *lists, int *ret_val)
{
	int		i;
	char	**cmd_rest;

	i = -1;
	while (cmd[++i])
	{
		if (!ft_strncmp(cmd[i], "<<", 3))
		{
			cmd_rest = heredoc_input(cmd, i, lists);
			free_split(cmd);
			identify_exec(cmd_rest, lists, ret_val);
			unlink("heredoc");
			free_exit(lists, cmd, 0);
			exit(0);
		}
		else if (!ft_strncmp(cmd[i], "<", 2))
		{
			cmd_rest = input(cmd, i, lists);
			free_split(cmd);
			identify_exec(cmd_rest, lists, ret_val);
			free_exit(lists, cmd, 0);
			exit(0);
		}
	}
}

void	redirect_input(char **cmd, t_lists *lists, int *ret_val)
{
	int		pid;

	pid = child_process();
	if (pid == 0)
		identify_input(cmd, lists, ret_val);
	wait(NULL);
	free_split(cmd);
}
