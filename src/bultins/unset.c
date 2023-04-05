/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:34:27 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/04/04 20:33:57 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	unset_variable(t_node *env, char *unseted_var)
{
	t_node	*aux;
	t_node	*swap_node;

	aux = env;
	while (aux->next)
	{
		if (!ft_strncmp(aux->next->content, unseted_var, \
		ft_strlen(unseted_var)))
		{
			swap_node = aux->next->next;
			free(aux->next->content);
			free(aux->next);
			aux->next = swap_node;
			break ;
		}
		aux = aux->next;
	}
}

int	unset(char **command, t_node *env)
{
	int		i;

	i = 0;
	while (command[++i])
		unset_variable(env, command[i]);
	free_split(command);
	return (0);
}
