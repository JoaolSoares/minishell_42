/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 20:41:49 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/02/16 19:51:59 by jlucas-s         ###   ########.fr       */
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
			if (!str[i])
				break ;	
			i++;
		}
		if (str[i] == ' ')
		{
			ft_putchar(' ');
			while (str[i] == ' ' && str[i])
				i++;
		}
		if (str[i] != ' ' && str[i] != '"' && str[i])
			ft_putchar(str[i]);
	}
}

void	echo(char *command)
{
	int	have_n;
	int	i;

	have_n = 0;
	i = 4;
	if (ft_strlen(command) > 4 && !ft_strncmp(command + 5, "-n", 2))
	{
		have_n = 1;
		i = 7;
	}
	while (command[i] == ' ')
		i++;
	echo_string(command + i);
	if (!have_n)
		ft_putchar('\n');
}
