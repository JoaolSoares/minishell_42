/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:54:58 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/03/22 20:57:07 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char	*catch_env(char *env_var, t_node *env)
{
	t_node *aux;
	int		i;

	i = 0;
	while (env_var[i] > 32)
		i++;
	aux = env;
	while (aux)
	{
		if (!ft_strncmp(aux->content, env_var, i))
			return (ft_strchr(aux->content, '=') + 1);
		aux = aux->next;
	}
	return (NULL);
}

static void	translate_env_var(t_aux *aux, int i, t_node *env, int return_value)
{
	int		j;
	char	*env_var;
	char	*temp;

	if (aux->cmd[i] == '$' && aux->cmd[i + 1])
	{
		if (aux->cmd[i + 1] == '?')
		{
			ft_pullchars(aux->cmd, i, 4);
			ft_pullchars(aux->cmd, i, 4);
			temp = ft_strdup(aux->cmd);
			free(aux->cmd);
			aux->cmd = ft_strinsert(temp, ft_itoa(return_value), i); //arrumar o malloc
			free(temp);	
		}
		else
		{
			j = i;
			while (aux->cmd[j] != ' ' && aux->cmd[j] != '"' && aux->cmd[j])
				j++;
			env_var = ft_until_strdup(aux->cmd + i + 1, j - i - 1);
			if (!catch_env(env_var, env))
				free(env_var);
			else
			{
				while (--j >= i)
					ft_pullchars(aux->cmd, j, 4);
				temp = ft_strdup(aux->cmd);
				free(aux->cmd);
				aux->cmd = ft_strinsert(temp, catch_env(env_var, env), i);
				free(temp);	
				free(env_var);
			}
		}
	}
}

static int	double_quote(t_aux *aux, int i, t_node *env, int return_value)
{
	ft_pullchars(aux->cmd, i, 4);
	while (aux->cmd[i] != '"' && aux->cmd[i])
	{
		if (aux->cmd[i] == '$')
			translate_env_var(aux, i, env, return_value);
		i++;
	}
	ft_pullchars(aux->cmd, i, 4);
	return (--i);
}

char	**split_command(char *cmd, t_node *env, int return_value)
{
	int		i;
	t_aux	*aux;
	char	**ret;

	aux = malloc(sizeof(t_aux));
	aux->cmd = ft_strdup(cmd);
	i = -1;
	while (aux->cmd[++i])
	{
		if (aux->cmd[i] == ' ')
			aux->cmd[i] = 4;
		else if (aux->cmd[i] == 39)
		{
			ft_pullchars(aux->cmd, i, 4);
			while (aux->cmd[i] != 39 && aux->cmd[i])
				i++;
			ft_pullchars(aux->cmd, i--, 4);
		}
		else if (aux->cmd[i] == '"')
			i = double_quote(aux, i, env, return_value);
		else if (aux->cmd[i] == '$')
			translate_env_var(aux, i, env, return_value);
	}
	ret = ft_split(aux->cmd, 4, 1);
	free(aux);
	return (ret);
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