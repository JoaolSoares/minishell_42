/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:15:55 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/02/15 22:48:22 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	*command;
	pid_t	pid;
	// char	**env;

	if (argc > 1 && argv)
		exit (1);

	// env = envp_copy();

	command = prompt(envp);
	while (command && ft_strncmp(command, "exit", 4))
	{
		pid = child_process();
		if (pid == 0)
			identify_exec(command, envp);
		wait(NULL);

		free(command);
		command = prompt(envp);
	}

	if (!command)
		ft_putchar('\n');
	free(command);

	// 
	char *copy;
	int i = -1;
	while (envp[++i])
	{
		copy = ft_strdup(envp[i]);
		envp[i] = calloc(sizeof(char), ft_strlen(envp[i]) + 1);
		ft_strlcpy(envp[i], copy, ft_strlen(copy) + 1);
		free(copy);
	}

	free_split(envp, 0);
	// 

	return (0);
}
