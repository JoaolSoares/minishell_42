/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:54:58 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/04/05 02:09:38 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
			i = simple_quote(aux, i);
		else if (aux->cmd[i] == '"')
			i = double_quote(aux, i, env, return_value);
		else if (aux->cmd[i] == '$')
			translate_env_var(aux, i, env, return_value);
	}
	ret = ft_split(aux->cmd, 4, 1);
	free(aux);
	return (ret);
}
