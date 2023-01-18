/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:15:55 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/01/18 20:09:57 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	print_pwd(char *envp[])
{
	static int	i;

	i--;
	while (envp[++i])
		if (!ft_strncmp(envp[i], "PWD", 3))
		{
			ft_printf("%s:~%s\n$> ", "Minishell", envp[i] + 4);
			return ;
		}
}

int	main(int argc, char *argv[], char *envp[])
{
	char	*command;

	if (argc > 1)
		exit (1);

	print_pwd(envp);
	command = get_next_line(STDIN_FILENO);
	while (command && ft_strncmp(command, "exit", 4))
	{
		wait(NULL);
		child_process(command, envp);

		free(command);
		print_pwd(envp);
		command = get_next_line(STDIN_FILENO);
	}
	if (!command)
		ft_putchar('\n');
	get_next_line(-1);
	free(command);

	return (0);
}
