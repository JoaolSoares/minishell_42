/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:35:50 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/03/15 22:07:32 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	have_char(char **split_cmd, char *c)
{
	int	i;

	i = -1;
	while (split_cmd[++i])
		if (!ft_strncmp(split_cmd[i], c, ft_strlen(c) + 1))
			return (1);
	return (0);
}

void	identify_exec(char *command, t_lists *lists, int *ret_val)
{
	char	**split_cmd;

	split_cmd = split_command(command, lists->env, *ret_val);
	if (split_cmd[0])
	{
		if (have_char(split_cmd, ">") || have_char(split_cmd, ">>") )
			redirect_output(split_cmd, lists, ret_val);
		else if (have_char(split_cmd, "<"))
			redirect_input(split_cmd, lists, ret_val);
		// else if (have_char(split_cmd, '<'))
		// 	redirect_input(split_cmd, lists->env);
		else if (have_char(split_cmd, "|"))
			pipe_exec(split_cmd, lists->env);
		else if (!ft_strncmp(split_cmd[0], "exit", ft_strlen(split_cmd[0]) + 1))
			ft_exit(split_cmd, lists);
		else if (!ft_strncmp(split_cmd[0], "cd", ft_strlen(split_cmd[0]) + 1))
			*ret_val = cd(split_cmd, lists->env);
		else if (!ft_strncmp(split_cmd[0], "echo", ft_strlen(split_cmd[0]) + 1))
			*ret_val = echo(split_cmd);
		else if (!ft_strncmp(split_cmd[0], "unset", ft_strlen(split_cmd[0]) + 1))
			*ret_val = unset(split_cmd, lists->env);
		else if (!ft_strncmp(split_cmd[0], "export", ft_strlen(split_cmd[0]) + 1))
			*ret_val = export(split_cmd, lists->env);
		else if (!ft_strncmp(split_cmd[0], "env", ft_strlen(split_cmd[0]) + 1))
			*ret_val = print_linked_list(lists->env);
		else if (!ft_strncmp(split_cmd[0], "history", ft_strlen(split_cmd[0]) + 1))
			*ret_val = print_linked_list(lists->history);
		else
			*ret_val = execve_return(split_cmd, lists);
	}
	free_split(split_cmd);
}
