/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:48:08 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/04/12 21:49:21 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	sigint_handler(int sig_num)
{
	if (sig_num == SIGINT)
	{
		ft_putchar('\n');
		print_terminal_line();
		ft_putchar('\n');
		rl_on_new_line();
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void kill_process(int signum)
{
	(void)signum;
	free_exit(struct_exit->lists, struct_exit->cmd, 1);
	free(struct_exit);
	rl_clear_history();
	exit(1);
}
