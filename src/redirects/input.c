/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:56:39 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/04/18 21:58:32 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_exit	*g_struct_exit;

char	**input(char **cmd, int i, t_lists *lists)
{
	int		fd;
	char	**cmd_rest;

	fd = open(cmd[i + 1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("minishell: %s: No such file or directory\n", cmd[i + 1]);
		free_exit(lists, cmd, 1);
		free(g_struct_exit);
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

void	heredoc_content(char **cmd, int i)
{
	int		fd;
	char	*line;

	fd = open("heredoc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	line = ft_strdup(" ");
	while (ft_strncmp(line, cmd[i + 1], ft_strlen(line) + 1))
	{
		free(line);
		line = readline("> ");
		if (!line)
		{
			ft_printf("-bash: warning: here-document delimited by end-of-file \
(wanted `%s')", cmd[i + 1]);
			close(fd);
			free(line);
			unlink("heredoc");
			kill_process(1);
		}
		if (ft_strncmp(line, cmd[i + 1], ft_strlen(cmd[i + 1])))
			ft_putendl_fd(line, fd);
	}
	close(fd);
	free(line);
}

char	**heredoc_input(char **cmd, int i)
{
	int		fd;
	char	**cmd_rest;

	heredoc_content(cmd, i);
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
			cmd_rest = heredoc_input(cmd, i);
			unlink("heredoc");
		}
		else if (!ft_strncmp(cmd[i], "<", 2))
			cmd_rest = input(cmd, i, lists);
		if (!ft_strncmp(cmd[i], "<<", 3) || !ft_strncmp(cmd[i], "<", 2))
		{
			free_split(cmd);
			free(g_struct_exit);
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
	signal(SIGINT, SIG_IGN);
	if (pid == 0)
	{
		g_struct_exit = malloc(sizeof(t_exit));
		g_struct_exit->lists = lists;
		g_struct_exit->cmd = ft_mtxdup(cmd);
		free_split(cmd);
		signal(SIGINT, kill_process);
		identify_input(g_struct_exit->cmd, g_struct_exit->lists, ret_val);
	}
	wait(NULL);
	signal(SIGINT, sigint_handler);
	free_split(cmd);
}
