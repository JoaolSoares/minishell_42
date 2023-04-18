/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:12:33 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/04/13 20:35:40 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//  INCLUDES  //
# include "../lib/include/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <dirent.h>
# include <signal.h>

//  DEFINES  //
# define UCYAN    "\001\e[4;36m\002"
# define MAGENTA "\001\e[0;35m\002"
# define WHITE   "\001\e[0;37m\002"
# define SIZE_PATH 256

//  STRUCTS  //
typedef struct s_node
{
	char			*content;
	struct s_node	*next;

}	t_node;

typedef struct s_lists
{
	t_node			*env;
	t_node			*history;

}	t_lists;

typedef struct s_aux
{
	char			*cmd;

}	t_aux;

typedef struct s_pipes_data
{
	int				**pipefd;
	int				num_pipes;
	int				index;
	int				position;
	char			**cmd_rest;
	int				ret_pipe[2];

}	t_pipes_data;

typedef struct s_exit
{
	t_lists	*lists;
	char	**cmd;

}	t_exit;

extern t_exit	*struct_exit;

//  FUNCTIONS  //
//  PROMPT  //
char	*prompt(void);
void	print_terminal_line(void);

//  SIGNAL  //
void	sigint_handler(int sig_num);
void	kill_process(int signum);

//  LINKED LIST  //
void	envp_linked_list(t_node **root, char **envp);
void	insert_in_list(t_node **node, char *content);
void	add_in_history(t_node **history, char *command);
int		print_linked_list(t_node *root, char **command);

//  FORK  //
pid_t	child_process(void);
void	child_execve(int *pipe_fd, t_lists *lists, char **split_cmd);

//  FREE  //
void	free_split(char **split);
void	free_main(t_lists *lists, char *command);
void	free_exit(t_lists *lists, char **command, int opt);
void	free_linked_list(t_node *root);

//  COMMANDS  //
void	identify_exec(char **split_cmd, t_lists *lists, int *ret_val);
char	**basic_split_command(char *cmd);

//  PARSER  //
char	**split_command(char *cmd, t_node *env, int return_value);
void	translate_env_var(t_aux *aux, int i, t_node *env, int return_value);

int		print_env(t_node *root, char **command);

void	ft_exit(char **command, t_lists *lists);

int		execve_return(char **split_cmd, t_lists *lists);

int		echo(char **command);

int		cd(char **command, t_node *env);
void	update_pwd(t_node *env, char *new_path, char *updater);
void	update_oldpwd(t_node *env, char *new_path);

int		unset(char **command, t_node *env);
void	unset_variable(t_node *env, char *unseted_var);
int		export(char **command, t_node *env);
char	*ft_until_strdup(const char *s, size_t index);

//  REDIRECTS  //
void	redirect_output(char **cmd, t_lists *lists, int *ret_val);
void	redirect_input(char **cmd, t_lists *lists, int *ret_val);
char	**str_rest(int delete, int size, char **cmd);

//  PIPE  //
void	pipe_exec(char **command, t_lists *lists, int *ret_val);
int		**open_pipes(int num);
void	close_pipes(int **pipes, int num, int opt);
void	call_childs(t_pipes_data *s_pipe, t_lists *lists, \
char **command, int *ret_val);
void	first_child(t_pipes_data *pipe, char **command, \
t_lists *lists, int *ret_val);
void	middle_child(t_pipes_data *pipe, char **command, \
t_lists *lists, int *ret_val);
void	final_child(t_pipes_data *s_pipe, char **command, \
t_lists *lists, int *ret_val);

#endif