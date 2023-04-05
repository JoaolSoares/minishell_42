/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:44:51 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/04/04 20:33:14 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*home_path(char *home_path, char *aux_path)
{
	if (aux_path[0] == '~')
		return (ft_strjoin(ft_strjoin(home_path, "/"), aux_path + 2));
	free(home_path);
	return (ft_strdup(aux_path));
}

static char	*hyphen_path(t_node *env)
{
	t_node	*aux;

	aux = env;
	while (aux->next)
	{
		if (!ft_strncmp(aux->content, "OLDPWD=", 7))
		{
			ft_printf("%s\n", aux->content + 7);
			return (ft_strdup(aux->content + 7));
		}
		aux = aux->next;
	}
	return (NULL);
}

static char	*get_path(char **command, t_node *env)
{
	if (!command[1])
		return (ft_strdup(getenv("HOME")));
	else if (!ft_strncmp(command[1], "~/", 2) && (ft_strlen(command[1])) > 2)
		return (home_path(ft_strdup(getenv("HOME")), command[1]));
	else if (!ft_strncmp(command[1], "~", 2) || \
	!ft_strncmp(command[1], "~/", 3))
		return (ft_strdup(getenv("HOME")));
	else if (!ft_strncmp(command[1], "-", 2))
		return ((hyphen_path(env)));
	else
		return (ft_strdup(command[1]));
}

int	cd(char **command, t_node *env)
{
	DIR		*dir;
	char	*path;
	char	buffer[SIZE_PATH];

	getcwd(buffer, SIZE_PATH);
	path = get_path(command, env);
	if (!path)
	{
		ft_printf("Minishell: cd: OLDPWD not set\n");
		return (1);
	}
	dir = opendir(path);
	if (!dir)
	{
		ft_printf("-minishell: cd: %s: No such file or directory\n", path);
		free(path);
		return (2);
	}
	update_pwd(env, buffer, "OLDPWD=");
	chdir(path);
	update_pwd(env, buffer, "PWD=");
	free(path);
	closedir(dir);
	free_split(command);
	return (0);
}
