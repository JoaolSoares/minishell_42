/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:15:55 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/03/03 16:39:59 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_lists	*lists;
	char	*command;
	int		return_value;

	if ((argc > 1 && argv))
		exit (1);

	lists = malloc(sizeof(t_lists));
	envp_linked_list(&lists->env, envp);

	return_value = 0;
	command = prompt();
	while (command && ft_strncmp(command, "exit", 4))
	{
		add_history(command);
		add_in_history(&lists->history, command);
	
		identify_exec(command, lists, envp, &return_value);
		wait(NULL);
	
		free(command);
		command = prompt();
	}

	if (!command)
		ft_putchar('\n');
	free_all(lists, command);

	return (0);
}
