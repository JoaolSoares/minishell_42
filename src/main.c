/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:15:55 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/02/16 20:44:27 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	*command;

	if (argc > 1 && argv)
		exit (1);

	envp_malloc(envp);

	command = prompt(envp);
	while (command && ft_strncmp(command, "exit", 4))
	{
		identify_exec(command, envp);
		wait(NULL);

		free(command);
		command = prompt(envp);
	}

	if (!command)
		ft_putchar('\n');

	free(command);
	free_split(envp, 0);

	return (0);
}
