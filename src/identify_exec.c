/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:35:50 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/03/13 20:26:00 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_pullchars(char *str, size_t index, char final_char)
{
	if (index < ft_strlen(str) + 1)
	{
		while (str[++index])
			str[index - 1] = str[index];
		str[index - 2] = final_char;
	}
}

char	*catch_env(char *env_var, t_node *env)
{
	t_node *aux;

	aux = env;
	while (aux)
	{
		if (!ft_strncmp(aux->content, env_var, ft_strlen(env_var)))
			return (ft_strchr(aux->content, '=') + 1);
		aux = aux->next;
	}
	return (NULL);
}

void	translate_env_var(char *cmd, int i, t_node *env)
{
	int		j;
	char	*env_var;
	char	*temp;
	
	if (cmd[i] == '$')
	{
		j = i;
		while (cmd[j] != ' ' && cmd[j] != '"' && cmd[j])
			j++;
		
		env_var = ft_until_strdup(cmd + i + 1, j - i - 1);
		if (!catch_env(env_var, env))
		{
			free(env_var);
			i++;
		}
		else
		{
			while (--j >= i)
			{
				cmd[j] = 4;
			}
			temp = ft_strdup(cmd);
			free(cmd);
			cmd = ft_strinsert(temp, catch_env(env_var, env), i);
			free(env_var);
			free(temp);	
		}
	}
}

char	**split_command(char *cmd, t_node *env)
{
	int		i;
	// 	int		j;
	// char	*env_var;
	// char	*temp;

	i = -1;
	while (cmd[++i])
	{
		if (cmd[i] == ' ')
			cmd[i] = 4;
		else if (cmd[i] == 39)
		{
			ft_pullchars(cmd, i, 4);
			while (cmd[i] != 39 && cmd[i])
				i++;
			ft_pullchars(cmd, i--, 4);
		}
		else if (cmd[i] == '"')
		{
			ft_pullchars(cmd, i, 4);
			while (cmd[i] != '"' && cmd[i])
			{
				translate_env_var(cmd, i, env);
				i++;
			}
			ft_pullchars(cmd, i--, 4);
		}
		else
		{	
			translate_env_var(cmd, i, env);
		}
	}
	return (ft_split(cmd, 4, 1));
}

//original
// char	**split_command(char *command) //fazer com que a primeira aspas faça igual a ultima e puxa os caracteers para tras
// {
// 	int		i;
// 	int		j;
// 	char	quote_type;

// 	i = -1;
// 	while (command[++i])
// 	{
// 		if (command[i] == ' ')
// 			command[i] = 4;
// 		if (command[i] == '"' || command[i] == 39)
// 		{
// 			quote_type = command[i];
// 			command[i] = 4;
// 			while (command[i] && command[i] != quote_type)
// 				i++;
// 			if (command[i] == quote_type)
// 			{
// 				j = i;
// 				while (command[++j])
// 					command[j - 1] = command[j];
// 				command[--j] = 4;
// 			}
// 		}
// 	}
// 	return (ft_split(command, 4, 0));
// }

int	have_pipe(char **split_cmd)
{
	int	i;

	i = -1;
	while (split_cmd[++i])
		if (!ft_strncmp(split_cmd[i], "|", 2))
			return (1);
	return (0);
}

void	identify_exec(char *command, t_lists *lists, int *ret_val)
{
	char	**split_cmd;

	split_cmd = split_command(ft_strdup(command), lists->env);
	if (split_cmd[0])
	{
		if (have_pipe(split_cmd))
			pipe_exec(split_cmd, lists->env);
		else if (!ft_strncmp(split_cmd[0], "exit", ft_strlen(split_cmd[0]) + 1))
			ft_exit(split_cmd, lists);
		else if (!ft_strncmp(split_cmd[0], "cd", ft_strlen(split_cmd[0]) + 1))
			*ret_val = cd(split_cmd, lists->env);
		else if (!ft_strncmp(split_cmd[0], "echo", ft_strlen(split_cmd[0]) + 1))
			*ret_val = echo(split_cmd, lists->env, ret_val);
		else if (!ft_strncmp(split_cmd[0], "unset", ft_strlen(split_cmd[0]) + 1))
			*ret_val = unset(split_cmd, lists->env);
		else if (!ft_strncmp(split_cmd[0], "export", ft_strlen(split_cmd[0]) + 1))
			*ret_val = export(split_cmd, lists->env);
		else if (!ft_strncmp(split_cmd[0], "env", ft_strlen(split_cmd[0]) + 1))
			*ret_val = print_linked_list(lists->env);
		else if (!ft_strncmp(split_cmd[0], "history", ft_strlen(split_cmd[0]) + 1))
			*ret_val = print_linked_list(lists->history);
		else
			*ret_val = execve_return(split_cmd, lists->env);
	}
	free_split(split_cmd);
}
