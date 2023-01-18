/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:58:20 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/01/18 20:00:33 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	child_process(char *command, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		exit (2);
	if (pid == 0)
		exec_command(command, envp);
	
	wait(NULL);
}