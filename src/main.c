/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:15:55 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/01/18 16:53:59 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	print_pwd(char *envp[])
{
	int	i;
	char	*user;
	char	*pwd;

	i = -1;
	while (envp[++i])
	{
		if (!ft_strncmp(envp[i], "USER", 4))
			user = ft_strdup(envp[i] + 5);
		else if (!ft_strncmp(envp[i], "PWD", 3))
			pwd = ft_strdup(envp[i] + 4);
	}
	ft_printf("%s:~%s$> ", user, pwd);
	free(user);
	free(pwd);
}

int	main(int argc, char *argv[], char *envp[])
{
	char	*command;

	if (argc > 1)
		return (1);

	print_pwd(envp);
	command = get_next_line(STDIN_FILENO);
	while (command && ft_strncmp(command, "exit", 4))
	{
		
		
		
		free(command);
		print_pwd(envp);
		command = get_next_line(STDIN_FILENO);
	}
	get_next_line(-1);
	free(command);

	return (0);
}
