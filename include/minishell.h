/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:12:33 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/03/09 22:02:44 by jlucas-s         ###   ########.fr       */
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
#include <signal.h>

//  DEFINES  //
# define UCYAN    "\001\e[4;36m\002"
# define MAGENTA "\001\e[0;35m\002"
# define WHITE   "\001\e[0;37m\002"
# define SIZE_PATH 256

//  STRUCTS  //
typedef struct	s_node
{
	char			*content;
	struct s_node	*next;

}	t_node;

typedef struct	s_lists
{
	t_node	*env;
	t_node	*history;

}	t_lists;

//  FUNCTIONS  //
//  PROMPT  //
char	*prompt();
void	print_terminal_line(void);

//  LINKED LIST  //
void	envp_linked_list(t_node **root, char **envp);
void	insert_in_list(t_node **node, char *content);
void	add_in_history(t_node **history, char *command);
int		print_linked_list(t_node *root);

//  FORK  //
pid_t	child_process(void);

//  PIPE  //
int	pipe_exec(char **command, t_node *env);

//  FREE  //
void	free_split(char **split);
void	free_all(t_lists *lists, char *command);
void	free_exit(t_lists *lists, char **command);

//  COMMANDS  //
void	identify_exec(char *command, t_lists *lists, int *ret_val);

void	ft_exit(char **command, t_lists *lists);

int		execve_return(char **split_cmd, t_node *env);

int		echo(char **command, t_node *env, int *return_value);

int		cd(char **command, t_node *env);
void	update_pwd(t_node *env, char *new_path, char *updater);
void	update_oldpwd(t_node *env, char *new_path);

int		unset(char **command, t_node *env);
void	unset_variable(t_node *env, char *unseted_var);
int		export(char **command, t_node *env);
char	*ft_until_strdup(const char *s, size_t index);

#endif