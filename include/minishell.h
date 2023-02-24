/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:12:33 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/02/24 19:35:31 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//  INCLUDES  //
#include "../lib/include/libft.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <dirent.h>

//  STRUCTS  //
typedef struct	s_node
{
	char			*content;
	struct s_node	*next;

}	t_node;


//  FUNCTIONS  //

char	*prompt();

pid_t	child_process(void);

//  LINKED LIST  //
void	envp_linked_list(t_node **root, char **envp);
void	insert_in_list(t_node **node, char *content);
void	free_linked_list(t_node *root);
void	print_linked_list(t_node *root);

//  ALLOCS  //
// void	envp_malloc(char *envp[]);
char	**envp_copy(char **envp);
void	free_split(char **split, int opt);

//  COMMANDS  //
void	identify_exec(char *command, t_node *env, char **envp);

void	execve_command(char **command, char **envp);
void	echo(char *command);
int		cd(char *command, t_node *env);

int		unset(char *command, t_node *env);
void	export(char *command, t_node *env);

#endif