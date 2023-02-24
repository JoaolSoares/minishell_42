/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:15:55 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/02/24 19:03:03 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	*command;
	t_node	*env;

	if (argc > 1 && argv)
		exit (1);

	env = NULL;
	envp_linked_list(&env, envp);

	command = prompt();
	while (command && ft_strncmp(command, "exit", 4))
	{
		identify_exec(command, env, envp);
		wait(NULL);

		free(command);
		command = prompt();
	}

	if (!command)
		ft_putchar('\n');

	free(command);
	free_linked_list(env);

	return (0);
}
