/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:36:37 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/03/01 22:56:37 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	print_terminal_line(void)
{
	char	buffer[SIZE_PATH];

	getcwd(buffer, SIZE_PATH);
	ft_printf("Minishell:");
	if (ft_strncmp(buffer, getenv("HOME"), ft_strlen(getenv("HOME")) + 1))
	{
		if (ft_strlen(getenv("HOME")) > ft_strlen(buffer))
			ft_printf("%s", buffer);
		else
			ft_printf("~%s", buffer + ft_strlen(getenv("HOME")));
	}
	else
		ft_putchar('~');
	ft_printf("\n$>");
}

char	*prompt(void)
{
	print_terminal_line();
	return (readline(""));
}
