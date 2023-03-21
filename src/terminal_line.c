/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:36:37 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/03/20 22:03:09 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void    print_terminal_line(void)
{
    char    buffer[SIZE_PATH];

    getcwd(buffer, SIZE_PATH);
    ft_printf(MAGENTA "Minishell:" UCYAN);
    if (ft_strncmp(buffer, getenv("HOME"), ft_strlen(getenv("HOME")) + 1))
    {
        if (ft_strlen(getenv("HOME")) > ft_strlen(buffer))
            ft_printf("%s", buffer);
        else
            ft_printf("~%s", buffer + ft_strlen(getenv("HOME")));
    }
    else
        ft_putchar('~');
}

char    *prompt(void)
{
    print_terminal_line();
    return (readline(WHITE "\n$> "));
}