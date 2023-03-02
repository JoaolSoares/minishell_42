/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:58:20 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/03/01 22:58:40 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

pid_t	child_process(void)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		exit (20);
	return (pid);
}

// void	child_process(char *command, char **envp)
// {
// 	pid_t	pid;

// 	pid = fork();
// 	if (pid < 0)
// 		exit (20);
// 	if (pid == 0)
// 	{
// 		exec_command(command, envp);
// 		free(command);
// 		exit (21);
// 	}

// 	wait(NULL);
// }
