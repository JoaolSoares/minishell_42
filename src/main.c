/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:15:55 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/01/24 20:13:53 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	*command;
	pid_t	pid;

	if (argc > 1 && argv)
		exit (1);

	command = prompt(envp);
	while (command && ft_strncmp(command, "exit", 4))
	{
		pid = child_process();
		if (pid == 0)
		{
			exec_command(command, envp);
		}
		wait(NULL);


		free(command);
		command = prompt(envp);
	}

	if (!command)
		ft_putchar('\n');
	free(command);


	return (0);
}
