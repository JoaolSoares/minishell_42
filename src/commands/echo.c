/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 20:41:49 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/03/01 22:23:32 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	echo(char **command)
{
	int	have_n;
	int	i;

	have_n = 0;
	if (command[1] && !ft_strncmp(command[1], "-n", ft_strlen(command[1]) + 1))
		have_n = 1;
	i = 1 + have_n;
	while (command[i])
	{
		ft_putstr_fd(command[i++], STDOUT_FILENO);
		if (command[i] + 1)
			ft_putchar(' ');
	}
	if (!have_n)
		ft_putchar('\n');
}
