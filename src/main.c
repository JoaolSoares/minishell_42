/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:15:55 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/02/23 19:31:05 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	*command;
	char	**env;

	if (argc > 1 && argv)
		exit (1);

	env = envp_copy(envp);
	// envp_malloc(envp);

	command = prompt();
	while (command && ft_strncmp(command, "exit", 4))
	{
		identify_exec(command, env);
		wait(NULL);

		free(command);
		command = prompt();
	}

	if (!command)
		ft_putchar('\n');

	free(command);
	free_split(env, 1);

	return (0);
}
