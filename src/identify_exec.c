/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:35:50 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/02/14 18:58:04 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	identify_exec(char *command, char *envp[])
{
	if (!ft_strncmp(command, "echo", 4))
		echo(command);
	if (!ft_strncmp(command, "cd", 2))
		ft_printf("execução cd\n");
	else
		execve_command(ft_split(command, ' '), envp);
}
