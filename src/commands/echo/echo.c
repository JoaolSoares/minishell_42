/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 20:41:49 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/02/10 20:09:27 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	echo(char *command, char *envp[])
{
	int	i;

	i = 3;
	if (ft_strnstr(command + 5, "-n", 2))
	{
		command[4] = 4;
		i = 6;
	}
	while (ft_strchr(command + 5, '"') && ft_strchr(ft_strchr(command + 5, '"') + 1, '"'))
		if (ft_strchr(command + 5, '"') && ft_strchr(ft_strchr(command + 5, '"') + 1, '"'))
		{ // tem um problema pq ele deixa um espaço a mais que a original
			(ft_strchr(command + 5, '"'))[0] = 4;
			(ft_strchr(command + 5, '"'))[0] = 4;
		}
	while (command[++i] == ' ')
		command[i] = 4;
	execve_command(ft_split(command, 4), envp);
	free(command);
	exit (0);
}
