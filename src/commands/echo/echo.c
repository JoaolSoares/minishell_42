/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 20:41:49 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/02/14 19:10:44 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	echo_string(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '"')
		{
			while (str[++i] != '"' && str[i])
				ft_putchar(str[i]);
			i++;
		}
		if (str[i] == ' ')
		{
			ft_putchar(' ');
			while (str[i] == ' ' && str[i])
				i++;
		}
		if (str[i] != ' ' && str[i] != '"')
			ft_putchar(str[i]);
	}
}

void	echo(char *command)
{
	int	have_n;
	int	i;

	have_n = 0;
	i = 4;
	if (ft_strnstr(command + 5, "-n", 2))
	{
		have_n = 1;
		i = 7;
	}
	while (command[i] == ' ')
		i++;
	echo_string(command + i);
	if (!have_n)
		ft_putchar('\n');
	free(command);
	exit (0);
}

/*
void	echo(char *command, char *envp[])
{
	int	i;

	i = 3;
	if (ft_strnstr(command + 5, "-n", 2))
	{
		command[4] = 4;
		i = 6;
	}
	while (ft_strchr(command + 5, '"') && \
	(ft_strchr(command + 5, '"') + 1, '"'))
		if (ft_strchr(command + 5, '"') && \
		ft_strchr(ft_strchr(command + 5, '"') + 1, '"'))
		{ // tem um problema pq ele deixa um espaço a mais que a original
			(ft_strchr(command + 5, '"'))[0] = 4;
			if ((ft_strchr(command + 5, '"'))[1] == ' ')
			{
				(ft_strchr(command + 5, '"'))[1] = 4;
				(ft_strchr(command + 5, '"'))[0] = 4;
			}
			else
				(ft_strchr(command + 5, '"'))[0] = 4;
		}
	while (command[++i] == ' ')
		command[i] = 4;
	execve_command(ft_split(command, 4), envp);
	free(command);
	exit (0);
} 
*/