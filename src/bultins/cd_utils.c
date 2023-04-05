/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:21:37 by dofranci          #+#    #+#             */
/*   Updated: 2023/03/09 15:41:25 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	update_pwd(t_node *env, char *new_path, char *updater)
{
	t_node	*aux;
	char	*join;

	getcwd(new_path, SIZE_PATH);
	aux = env;
	while (aux->next)
	{
		if (!ft_strncmp(aux->content, updater, ft_strlen(updater)))
		{
			if (new_path[0] != '/')
				join = ft_strjoin(ft_strjoin(ft_strdup(updater), "/"), \
				new_path);
			else
				join = ft_strjoin(ft_strdup(updater), new_path);
			if (join[ft_strlen(join) - 1] == '/')
				join[ft_strlen(join) - 1] = 0;
			free(aux->content);
			aux->content = ft_strdup(join);
			free(join);
			break ;
		}
		aux = aux->next;
	}
	if (!ft_strncmp(updater, "OLDPWD=", 8) && !aux->next)
		update_oldpwd(env, new_path);
}

void	update_oldpwd(t_node *env, char *new_path)
{
	char	**command;
	char	*join;

	join = ft_strjoin(ft_strdup("export OLDPWD="), new_path);
	command = ft_split(join, ' ', 1);
	export(command, env);
	free_split(command);
}
