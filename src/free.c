/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:35:29 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/03/08 21:33:13 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

static void	free_linked_list(t_node *root)
{
	t_node	*aux;
	t_node	*aux_next;

	aux = root;
	aux_next = root->next;
	while (aux->next)
	{
		free(aux->content);
		free(aux);
		aux = aux_next;
		aux_next = aux->next;
	}
	free(aux->content);
	free(aux);
	free(aux_next);
}

void	free_all(t_lists *lists, char *command)
{
	rl_clear_history();	
	free_linked_list(lists->env);
	if (lists->history)
		free_linked_list(lists->history);
	free(command);
	free(lists);
}

void	free_exit(t_lists *lists, char **command)
{
	rl_clear_history();
	free_linked_list(lists->env);
	if (lists->history)
		free_linked_list(lists->history);
	free_split(command);
	free(lists);
}
