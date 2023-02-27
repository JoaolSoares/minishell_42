/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:33:17 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/02/27 19:20:08 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	export(char **command, t_node *env)
{
	int		i;
	char	*join;
	
	i = 1;
	while (command[i])
	{
		if (!ft_strchr(command[i], '='))
		{
			ft_printf("%s :is invalid\n", command[i]);
			break ;
		}
		if (ft_strlen(command[i]) == (ft_strlen_until(command[i], '=') + 1) && command[i + 1])
		{
			join = ft_strjoin(ft_strdup(command[i]), command[i + 1]);
			insert_in_list(&env, join);
			i += 2;
			free(join);
		}
		else
			insert_in_list(&env, command[i++]);
	}	
}