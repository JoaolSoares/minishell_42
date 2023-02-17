/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:36:37 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/02/16 19:40:52 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	print_terminal_line(char *envp[])
{
	static int	i;

	i--;
	while (envp[++i])
		if (!ft_strncmp(envp[i], "PWD=", 4))
		{
			ft_printf("%s:~%s\n$> ", "Minishell", envp[i] + 4);
			break ;
		}
}

char	*prompt(char *envp[])
{
	print_terminal_line(envp);
	return (readline(""));
}
