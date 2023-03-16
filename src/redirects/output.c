/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:17:43 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/03/15 21:50:38 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	redirect_output(char **cmd, t_lists *lists, int *ret_val)
{
	int	i;
	int	fd;

	int pid = child_process();

	if (pid == 0)
	{
		i = -1;
		while (cmd[++i])
		{
			if (!ft_strncmp(cmd[i], ">", 2))
			{
				fd = open(cmd[i + 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
				break ;
			}
			if (!ft_strncmp(cmd[i], ">>", 3))
			{
				fd = open(cmd[i + 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
				break ;
			}
		}
		
		dup2(fd, STDOUT_FILENO);
		identify_exec(cmd[i - 1], lists, ret_val);
		free_exit(lists, cmd);
		exit(0);
	}
	wait(NULL);
}
