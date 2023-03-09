/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:28:21 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/03/08 14:29:28 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

pid_t	child_process(void)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		exit (20);
	return (pid);
}
