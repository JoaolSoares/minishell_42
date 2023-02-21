/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:36:37 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/02/21 17:33:39 by jlucas-s         ###   ########.fr       */
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
			ft_printf("Minishell:~");
			if (ft_strncmp(envp[i] + 4, getenv("HOME"), ft_strlen(getenv("HOME")) + 1))	
				ft_printf("%s ", envp[i] + 4);
			ft_printf("\n$> ");
			break ;
		}
}

char	*prompt(char *envp[])
{
	print_terminal_line(envp);
	return (readline(""));
}
