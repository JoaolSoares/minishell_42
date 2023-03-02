/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:35:50 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/03/01 22:55:29 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**split_command(char *command)
{
	int		i;
	char	quote_type;

	i = -1;
	while (command[++i])
	{
		if (command[i] == ' ')
			command[i] = 4;
		if (command[i] == '"' || command[i] == 39)
		{
			quote_type = command[i];
			command[i] = 4;
			while (command[i] && command[i] != quote_type)
				i++;
			if (command[i] == quote_type)
				command[i] = 4;
		}
	}
	return (ft_split(command, 4));
}

void	identify_exec(char *command, t_node *env, char **envp)
{
	pid_t	pid;
	char	**split_cmd;

	split_cmd = split_command(command);
	if (!ft_strncmp(split_cmd[0], "cd", ft_strlen(split_cmd[0]) + 1))
		cd(split_cmd, env);
	else if (!ft_strncmp(split_cmd[0], "echo", ft_strlen(split_cmd[0]) + 1))
		echo(split_cmd);
	else if (!ft_strncmp(split_cmd[0], "unset", ft_strlen(split_cmd[0]) + 1))
		unset(split_cmd, env);
	else if (!ft_strncmp(split_cmd[0], "export", ft_strlen(split_cmd[0]) + 1))
		export(split_cmd, env);
	else if (!ft_strncmp(split_cmd[0], "env", ft_strlen(split_cmd[0]) + 1))
		print_linked_list(env);
	else
	{
		pid = child_process();
		if (pid == 0)
			execve_command(split_cmd, envp);
	}//sugestão: no futuro fazer uma função que traduz nossa linked pra uma mtx
	free_split(split_cmd);
}
