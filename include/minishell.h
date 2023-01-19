/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:12:33 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/01/19 20:37:01 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//	INCLUDES
#include "../lib/include/libft.h"
#include <sys/types.h>
#include <sys/wait.h>

//	STRUCTS

//	FUNCTIONS

char	*terminal_line(char *envp[], int del);

void	exec_command(char *command, char **envp);

void	child_process(char *command, char **envp);

#endif