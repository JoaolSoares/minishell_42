/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:34:27 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/02/24 19:32:04 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static void	unset_variable(t_node *env, char *unseted)
{
	t_node  *aux;
	t_node	*swap_node;

    aux = env;
    while (aux->next)
    {
        if (!ft_strncmp(aux->next->content, unseted, ft_strlen(unseted)))
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


int	unset(char *command, t_node *env)
{
	int		i;
	char	*unseted;

	i = 5;
	while (command[++i] == ' ') ;
	unseted = ft_strdup(command + i);

	///verificar se a variavel existe msm aqui

	unset_variable(env, unseted);

	free(unseted);
	return (0);
}
