/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:35:50 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/03/08 21:46:24 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"


char	**split_command(char *command) //fazer com que a primeira aspas faça igual a ultima e puxa os caracteers para tras
{
	int		i;
	int		j;
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
			{
				j = i;
				while (command[++j])
					command[j - 1] = command[j];
				command[--j] = 4;
			}
		}
	}
	return (ft_split(command, 4));
}

int	have_pipe(char **split_cmd)
{
	int	i;

	i = -1;
	while (split_cmd[++i])
		if (!ft_strncmp(split_cmd[i], "|", 2))
			return (1);
	return (0);
}

void	identify_exec(char *command, t_lists *lists, char **envp, int *ret_val)
{
	char	**split_cmd;

	split_cmd = split_command(command);
	if (split_cmd[0])
	{
		if (have_pipe(split_cmd))
			pipe_exec(split_cmd, lists->env);
		else if (!ft_strncmp(split_cmd[0], "exit", ft_strlen(split_cmd[0]) + 1))
			ft_exit(split_cmd, lists);
		else if (!ft_strncmp(split_cmd[0], "cd", ft_strlen(split_cmd[0]) + 1))
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
		else	//no futuro fazer uma função que traduz nossa linked pra uma mtx // precisa fazer
			*ret_val = execve_return(split_cmd, envp);
	}
	free_split(split_cmd);
}
