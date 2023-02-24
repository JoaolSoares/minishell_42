/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:56:46 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/02/24 18:57:30 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	free_linked_list(t_node *root)
{
	t_node *aux;
	t_node *aux_next;

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

void	insert_in_list(t_node **node, char *content)
{
	t_node *new_node;
	t_node *aux;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->content = ft_strdup(content);
	new_node->next = NULL;

	if (!*node)
	{
		*node = new_node;
		return ;
	}
	
	aux = *node;
	while (aux->next)
		aux = aux->next;
	aux->next = new_node;
}

void	envp_linked_list(t_node **root, char **envp)
{
	int		i;

	i = -1;
	while (envp[++i])
		insert_in_list(root, envp[i]);
}

void	print_linked_list(t_node *root)
{
	t_node *aux;

	aux = root;
	while (aux)
	{
		ft_printf("%s\n", aux->content);
		aux = aux->next;
	}
}