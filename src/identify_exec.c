/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:35:50 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/03/03 16:42:05 by jlucas-s         ###   ########.fr       */
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

void	identify_exec(char *command, t_lists *lists, char **envp, int *ret_val)
{
	char	**split_cmd;

	split_cmd = split_command(command);
	if (!ft_strncmp(split_cmd[0], "cd", ft_strlen(split_cmd[0]) + 1))
		*ret_val = cd(split_cmd, lists->env);
	else if (!ft_strncmp(split_cmd[0], "echo", ft_strlen(split_cmd[0]) + 1))
		*ret_val = echo(split_cmd, lists->env, ret_val);
	else if (!ft_strncmp(split_cmd[0], "unset", ft_strlen(split_cmd[0]) + 1))
		*ret_val = unset(split_cmd, lists->env);
	else if (!ft_strncmp(split_cmd[0], "export", ft_strlen(split_cmd[0]) + 1))
		*ret_val = export(split_cmd, lists->env);
	else if (!ft_strncmp(split_cmd[0], "env", ft_strlen(split_cmd[0]) + 1))
		*ret_val = print_linked_list(lists->env);
	else if (!ft_strncmp(split_cmd[0], "history", ft_strlen(split_cmd[0]) + 1))
		*ret_val = print_linked_list(lists->history);
	else	//sugestão: no futuro fazer uma função que traduz nossa linked pra uma mtx
		*ret_val = execve_return(split_cmd, envp);
	free_split(split_cmd);
}
