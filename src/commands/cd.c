/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:44:51 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/02/28 22:38:36 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void    update_pwd(t_node *env, char *new_path, char *updater)
{
    t_node  *aux;
    char    *join;

    aux = env;
    while (aux->next)
    {
        if (!ft_strncmp(aux->content, updater, ft_strlen(updater)))
        {
            if (new_path[0] != '/')
                join = ft_strjoin(ft_strjoin(ft_strdup(updater), "/"), new_path);
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
}

static char    *home_path(char *home_path, char *aux_path)
{
    if(aux_path[0] == '~')
        return (ft_strjoin(ft_strjoin(home_path, "/"), aux_path + 2));
    free(home_path);
    return (ft_strdup(aux_path));
}

static char *hyphen_path(t_node *env)
{
    t_node *aux;
    
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

static char    *get_path(char **command, t_node *env)
{

    if (!command[1])
        return (ft_strdup(getenv("HOME")));
    else if((command[1][0] == '~' || command[1][0] == '/' ) && (ft_strlen(command[0])) > 1)
        return (home_path(ft_strdup(getenv("HOME")), command[1]));
    else if (!ft_strncmp(command[1], "~", 2) || !ft_strncmp(command[1], "~/", 3))
        return (ft_strdup(getenv("HOME")));
    else if (!ft_strncmp(command[1], "-", 2))
        return ((hyphen_path(env)));
    else
       return (ft_strdup(command[1]));
    return (0);
}

int	cd(char **command, t_node *env)
{
	DIR*    dir;
	char    *path;
	char    buffer[SIZE_PATH];
    char    oldbuffer[SIZE_PATH];

    getcwd(oldbuffer, SIZE_PATH);
    path = get_path(command, env);
    // if(!path)
    // {
    //     ft_printf("Minishell: cd: OLDPWD not set\n");
    //     return(1);
    // }
    dir = opendir(path);
    if (!dir)
    {
        ft_printf("-minishell: cd: %s: No such file or directory\n", path);
        free(path);
        return (1);
    }

    chdir(path);
	getcwd(buffer, SIZE_PATH);
    update_pwd(env, buffer, "PWD=");
    update_pwd(env, oldbuffer, "OLDPWD=");
    free(path);
    closedir(dir);
    return (0);
}  
