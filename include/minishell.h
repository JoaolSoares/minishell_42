/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:12:33 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/02/15 22:46:15 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//	INCLUDES
#include "../lib/include/libft.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <dirent.h>

//	STRUCTS
// typedef struct s_data
// {
	
// }	t_data;

//	FUNCTIONS

char	*prompt(char *envp[]);

pid_t	child_process(void);



void	free_split(char **split, int opt);

void	identify_exec(char *command, char **envp);

void	execve_command(char **command, char **envp);
void	echo(char *command);
void	cd(char *command, char **envp);

#endif