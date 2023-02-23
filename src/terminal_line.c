/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:36:37 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/02/23 18:25:42 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	print_terminal_line()
{
	char buffer[256];

	getcwd(buffer, 256);
	ft_printf("Minishell:~");
	if (ft_strncmp(buffer, getenv("HOME"), ft_strlen(getenv("HOME")) + 1))
	{
		if (ft_strlen(getenv("HOME")) > ft_strlen(buffer))
			ft_printf("%s", buffer);
		else
			ft_printf("%s", buffer + ft_strlen(getenv("HOME")));
	}
	ft_printf("\n$>");
}

char	*prompt()
{
	print_terminal_line();
	return (readline(""));
}
