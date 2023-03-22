/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:15:55 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/03/21 14:28:04 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	sigint_handler(int sig_num)
{
	if (sig_num == SIGINT)
	{
		ft_putchar('\n');
		print_terminal_line();
		ft_putchar('\n');
		rl_on_new_line();
		rl_on_new_line();	
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_lists	*lists;
	char	*command;
	int		return_value;

	if ((argc > 1 && argv))
		exit (1);

	lists = malloc(sizeof(t_lists));
	envp_linked_list(&lists->env, envp);
	lists->history = NULL;

	return_value = 0;
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, sigint_handler);
	command = prompt();
	while (command)
	{
		if (command[0] != 0)
		{
			add_history(command);
			add_in_history(&lists->history, command);
		
			identify_exec(split_command(command, lists->env, return_value), lists, &return_value);
			wait(NULL);
		}
		free(command);
		command = prompt();
	}

	if (!command)
		ft_putchar('\n');
	free_all(lists, command);
	
	return (0);
}
