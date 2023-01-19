/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:36:37 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/01/19 20:39:05 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	print_terminal_line(char *envp[])
{
	static int	i;

	i--;
	while (envp[++i])
		if (!ft_strncmp(envp[i], "PWD", 3))
		{
			ft_printf("%s:~%s\n$> ", "Minishell", envp[i] + 4);
			break ;
		}
}

char	*terminal_line(char *envp[], int del)
{
	char	*line;

	if (del == -1)
		return (get_next_line(-1));
	print_terminal_line(envp);
	line = get_next_line(STDIN_FILENO);
	if (line)
		line[ft_strlen(line) - 1] = 0;
	return (line);
}