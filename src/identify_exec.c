/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:35:50 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/02/24 19:32:49 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	identify_exec(char *command, t_node *env, char **envp)
{
	pid_t	pid;
	int		i;

	i = -1;
	while (command[++i] == ' ') ;

	if (!ft_strncmp(command + i, "cd", 2))
		cd(command, env);
	else if (!ft_strncmp(command + i, "echo", 4))
		echo(command);
	else if (!ft_strncmp(command + i, "unset", 5))
		unset(command, env);
	else if (!ft_strncmp(command + i, "export", 6))
		export(command, env);
	else if (!ft_strncmp(command + i, "env", 3))
		print_linked_list(env);
	else
	{
		pid = child_process();
		if (pid == 0)
			execve_command(ft_split(command + i, ' '), envp);
	}		//sugestão: no futuro fazer uma função que traduz nossa linked pra uma mtx
}
