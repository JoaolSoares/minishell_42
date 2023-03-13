/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:33:17 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/03/09 16:10:55 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_until_strdup(const char *s, size_t index)
{
	char	*new_s;

	if (index > ft_strlen(s))
		index = ft_strlen(s);
	new_s = (char *)malloc(sizeof(char) * (index) + 1);
	if (!new_s)
		return (0);
	new_s[index] = 0;
	while (--index)
		new_s[index] = s[index];
	new_s[index] = s[index];
	return (new_s);
}

int	export(char **command, t_node *env)
{
	int		i;
	char	*aux_str;

	i = 1;
	while (command[i])
	{
		if (!ft_strchr(command[i], '='))
		{
			ft_printf("%s :is invalid\n", command[i]);
			return (1);
		}
		else if (ft_strlen(command[i]) == (ft_strlen_until(command[i], '=') + 1) \
		&& command[i + 1])
		{
			aux_str = ft_strjoin(ft_strdup(command[i]), command[i + 1]);
			unset_variable(env, command[i]);
			insert_in_list(&env, aux_str);
			free(aux_str);
			i += 2;
		}
		else			
		{
			aux_str = ft_until_strdup(command[i], ft_strlen_until(command[i], '=') + 1);
			unset_variable(env, aux_str);
			free(aux_str);
			insert_in_list(&env, command[i++]);
		}
	}
	return (0);
}
