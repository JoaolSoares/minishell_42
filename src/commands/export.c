/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:33:17 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/02/28 20:36:16 by dofranci         ###   ########.fr       */
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
