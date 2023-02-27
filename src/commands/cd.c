/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:44:51 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/02/27 18:31:02 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void    update_pwd(t_node *env, char *new_pwd)
{
    t_node  *aux;
    char    *join;

    aux = env;
    while (aux->next)
    {
        if (!ft_strncmp(aux->content, "PWD=", 4))
        {
            if (new_pwd[0] != '/')
                join = ft_strjoin(ft_strjoin(ft_strdup("PWD="), "/"), new_pwd);
            else
                join = ft_strjoin(ft_strdup("PWD="), new_pwd);
            if (join[ft_strlen(join) - 1] == '/')
                join[ft_strlen(join) - 1] = 0;
            free(aux->content);
            aux->content = ft_strdup(join);
            free(join);
            break ;
        }
        aux = aux->next;
    }
}

static char    *home_path(char *home_path, char *aux_path)
{
    if(aux_path[0] == '~')
        return (ft_strjoin(ft_strjoin(home_path, "/"), aux_path + 2));
    free(home_path);
    return (ft_strdup(aux_path));
}

static char    *get_path(char **command)
{
    if (!command[1])
        return (ft_strdup(getenv("HOME")));
    else if((command[1][0] == '~' || command[1][0] == '/' ) && (ft_strlen(command[0])) > 1)
        return (home_path(ft_strdup(getenv("HOME")), command[1]));
    else if (!ft_strncmp(command[1], "~", 2) || !ft_strncmp(command[1], "~/", 3))
        return (ft_strdup(getenv("HOME")));
    else
       return( ft_strdup(command[1]));
}

int	cd(char **command, t_node *env)
{
	DIR*    dir;
	char    *path;
	char    buffer[256];

    path = get_path(command);
    dir = opendir(path);
    if (!dir)
    {
        ft_printf("-minishell: cd: %s: No such file or directory\n", path);
        free(path);
        return (1);
    }

    chdir(path);
	getcwd(buffer, 256);
    update_pwd(env, buffer);

    free(path);
    closedir(dir);
    return (0);
}   
