/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:33:17 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/02/24 20:01:00 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	export(char *command, t_node *env)
{
	int		i;
	int		j;
	char	*join;
	char	*var_name;
	char	*var_content;
	
	i = 6;
	while (command[++i] == ' ');
	
	var_name = malloc(sizeof(char) * (ft_strlen_until(command, '=') - i) + 1);

	j = 0;
	while ((size_t)i < ft_strlen_until(command, '='))
		var_name[j++] = command[i++];
	var_name[j] = 0;

	if (command[++i] == '"' && ft_strchr(command + i + 1, '"')) // '' sem nada ""
	{
		j = 0;
		var_content = malloc(sizeof(char) * (ft_strlen_until(command + i + 1, '"') + 1));
		while (command[++i] != '"')
			var_content[j++] = command[i];
		var_content[j] = 0;
	}
	else
	{
		ft_printf("ERROR\n");
		free(var_name);
		return ;
	}
	
	join = ft_strjoin(ft_strjoin(var_name, "="), var_content);
	insert_in_list(&env, join);
	
	free(var_content);
	free(join);
	return ;
}

