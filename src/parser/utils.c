/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 21:30:06 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/04/04 21:34:19 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	parser(int i, t_aux *aux, t_node *env)
{
	int		j;
	char	*temp;
	char	*env_var;

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

void	translate_env_var(t_aux *aux, int i, t_node *env, int return_value)
{
	char	*temp;
	char	*str_num;

	if (aux->cmd[i] == '$' && aux->cmd[i + 1])
	{
		if (aux->cmd[i + 1] == '?')
		{
			ft_pullchars(aux->cmd, i, 4);
			ft_pullchars(aux->cmd, i, 4);
			temp = ft_strdup(aux->cmd);
			free(aux->cmd);
			str_num = ft_itoa(return_value);
			aux->cmd = ft_strinsert(temp, str_num, i);
			free(str_num);
			free(temp);
		}
		else
			parser(i, aux, env);
	}
}

char	*catch_env(char *env_var, t_node *env)
{
	t_node	*aux;
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

int	double_quote(t_aux *aux, int i, t_node *env, int return_value)
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

int	simple_quote(t_aux *aux, int i)
{
	ft_pullchars(aux->cmd, i, 4);
	while (aux->cmd[i] != 39 && aux->cmd[i])
		i++;
	ft_pullchars(aux->cmd, i--, 4);
	return (i);
}
