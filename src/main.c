/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:15:55 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/01/19 20:37:13 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	*command;

	if (argc > 1)
		exit (1);

	command = terminal_line(envp, 0);
	while (command && ft_strncmp(command, "exit", 4))
	{
		child_process(command, envp);
	

		free(command);
		command = terminal_line(envp, 0);
	}

	if (!command)
		ft_putchar('\n');
	terminal_line(envp, -1);
	free(command);

	return (0);
}
