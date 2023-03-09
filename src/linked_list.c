/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:56:46 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/03/08 21:32:58 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	add_in_history(t_node **history, char *command)
{
	char		*join;
	char		*num;
	static int	i;

	num = ft_itoa(++i);
	join = ft_strjoin(ft_strjoin(num, " "), command);
	insert_in_list(history, join);
	free(join);
}

void	insert_in_list(t_node **node, char *content)
{
	t_node	*new_node;
	t_node	*aux;

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

	*root = NULL;
	i = -1;
	while (envp[++i])
		insert_in_list(root, envp[i]);
}

int	print_linked_list(t_node *root)
{
	t_node	*aux;

	aux = root;
	while (aux)
	{
		ft_printf("%s\n", aux->content);
		aux = aux->next;
	}
	return (0);
}
