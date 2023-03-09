/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 21:02:00 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/03/08 21:26:54 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_exit(char **command, t_lists *lists)
{
	int exit_num;
	
	if (!command[1])
	{
		free_exit(lists, command);
		exit(0);
	}
	else if (command[2])
		ft_printf("logout\n-minishell: exit: too many arguments\n");
	else if (ft_str_isnum(command[1]))
	{
		exit_num = ft_atoi(command[1]);
		free_exit(lists, command);
		exit(exit_num);
	}
	else
	{
		ft_printf("logout\n-minishell: exit: %s: numeric argument requireds\n", 
		command[1]);
		free_exit(lists, command);
		exit(2);
	}
}