/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:56:39 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/03/15 22:05:06 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	redirect_input(char **cmd, t_lists *lists, int *ret_val)
{
	int	i;
	int	fd;

	int pid = child_process();

	if (pid == 0)
	{
		i = -1;
		while (ft_strncmp(cmd[++i], "<", 2)) ; 

		fd = open(cmd[i + 1], O_RDONLY);
		if (fd < 0)
		{
			ft_printf("minishell: %s: No such file or directory", cmd[i + 1]);
			free_exit(lists, cmd);
			exit(1);
		}
		
		dup2(fd, STDIN_FILENO);
		identify_exec(ft_strjoin(ft_strjoin(ft_strdup(cmd[i - 2]), " "), cmd[i - 1]), lists, ret_val);
		free_exit(lists, cmd);
		exit(0);
	}
	wait(NULL);
}