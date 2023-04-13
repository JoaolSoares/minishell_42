/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:38:36 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/04/12 16:39:54 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	print_env(t_node *root, char **command)
{
	t_node	*aux;

	aux = root;
	while (aux)
	{
		if (ft_strchr(aux->content, '='))
			ft_printf("%s\n", aux->content);
		aux = aux->next;
	}
	free_split(command);
	return (0);
}
