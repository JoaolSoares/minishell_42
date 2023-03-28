/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:56:39 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/03/27 23:39:34 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// static char **fodace(int start, int end, char **cmd)
// {
// 	char	*aux_str;
// 	char	*temp;

// 	aux_str = ft_strdup(cmd[start]);
// 	while (++start <= end && cmd[start])
// 	{
// 		temp = ft_strdup(aux_str);
// 		free(aux_str);
// 		aux_str = ft_strjoin(ft_strjoin(temp, "\4"), cmd[start]);
// 	}
	
// 	return (ft_split(aux_str, 4, 1));
// }

static char **fodace(int delete, int size, char **cmd)
{
	char	*aux_str;
	char	*temp;
	int		i;

	i = 0;
	while (i >= delete && i <= delete + size)
		i++;
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
		cmd_rest = fodace(i + 2, 1000, cmd);
	else
		cmd_rest = fodace(0, i - 1, cmd);
	
	return(cmd_rest);
}

char	**heredoc_input(char **cmd, int i, t_lists *lists)
{
	int		fd;
	char	**cmd_rest;
	char	*line;

	fd = open("heredoc", O_WRONLY  | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		ft_printf("minishell: %s: No such file or directory\n", cmd[i + 1]);
		free_exit(lists, cmd, 1);
		exit(1);
	}
	line = ft_strdup("");
	while(ft_strncmp(line, cmd[i + 1], ft_strlen(line) + 1))
	{
		free(line);
		line = readline("> ");
		if (!line)
		{
			free(line);
			close(fd);
			return(NULL);
		}
		if (ft_strncmp(line, cmd[i + 1], ft_strlen(cmd[i + 1])))
			ft_putendl_fd(line, fd);
	}
	close(fd);
	free(line);
	fd = open("heredoc", O_RDONLY);
	dup2(fd, STDIN_FILENO);
	if (cmd[i + 2])
		cmd_rest = fodace(i, 1, cmd);
	else
		cmd_rest = fodace(i, 1, cmd);
	close(fd);
	return (cmd_rest);
}

void	redirect_input(char **cmd, t_lists *lists, int *ret_val)
{
	int		i;
	int		pid;
	char	**cmd_rest;

	pid = child_process();
	if (pid == 0)
	{
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
	wait(NULL);
}

// void	redirect_input(char **cmd, t_lists *lists, int *ret_val)
// {
// 	int		i;
// 	int		fd;
// 	int		pid;
// 	char	**cmd_rest;

// 	pid = child_process();
// 	if (pid == 0)
// 	{
// 		i = -1;
// 		while (ft_strncmp(cmd[++i], "<", 2)) ; 
// 		fd = open(cmd[i + 1], O_RDONLY);
// 		if (fd < 0)
// 		{
// 			ft_printf("minishell: %s: No such file or directory\n", cmd[i + 1]);
// 			free_exit(lists, cmd, 1);
// 			exit(1);
// 		}
// 		dup2(fd, STDIN_FILENO);
// 		if (cmd[i + 2])
// 			cmd_rest = fodace(i + 2, 1000, cmd);
// 		else
// 			cmd_rest = fodace(0, i - 1, cmd);
// 		free_split(cmd);
// 		identify_exec(cmd_rest, lists, ret_val);
// 		free_exit(lists, cmd, 0);
// 		exit(0);
// 	}
// 	wait(NULL);
// }
