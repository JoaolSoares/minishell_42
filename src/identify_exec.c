/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:35:50 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/02/16 20:33:25 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	identify_exec(char *command, char *envp[])
{
	pid_t	pid;

	if (!ft_strncmp(command, "cd", 2))
		cd(command, envp);
	else if (!ft_strncmp(command, "echo", 4))
		echo(command);
	else
	{
		pid = child_process();
		if (pid == 0)
			execve_command(ft_split(command, ' '), envp);
	}
}
