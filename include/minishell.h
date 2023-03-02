/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:12:33 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/03/01 21:52:28 by dofranci         ###   ########.fr       */
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

// DEFINES //
# define SIZE_PATH 256

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

void	free_split(char **split);

//  COMMANDS  //
void	identify_exec(char *command, t_node *env, char **envp);

void	execve_command(char **command, char **envp);
void	echo(char **command);
int		cd(char **command, t_node *env);
void    update_pwd(t_node *env, char *new_path, char *updater);
void	update_oldpwd(t_node *env, char *new_path);

int		unset(char **command, t_node *env);
void	export(char **command, t_node *env);

#endif