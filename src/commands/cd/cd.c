/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:44:51 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/02/16 22:19:34 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static void    update_pwd(char *envp[], char *new_pwd)
{
    int     i;
    char    *join;

    i = -1;
    while (envp[++i])
    {
        if (!ft_strncmp(envp[i], "PWD=", 4))
        {
            join = ft_strjoin(ft_strdup("PWD="), new_pwd);
            free(envp[i]);
            envp[i] = ft_strdup(join);
            new_pwd[0] = 'a';
            free(join);
            break ;
        }
    }
}

void cd(char *command, char *envp[])
{
    DIR*    dir;
    char    *tmp_path;
    char    *path;
    int     i;

    tmp_path = ft_strdup(getenv("HOME"));

    i = 1;
    while(command[++i] == ' ') ;

    if(command[i] == '~' && ft_strlen(command) > 4)
        path = ft_strjoin(ft_strjoin(tmp_path, "/"), command + i + 2);
    else if(command[i] == '/')
    {
        path = ft_strdup(command + i);
        free(tmp_path);
    }
    else
    {
        path = ft_strdup(tmp_path);
        free(tmp_path);
    }
    
    dir = opendir(path);
    if (!dir)
        exit(89);

    chdir(path);
    update_pwd(envp, path);


    free(path);
    closedir(dir);
}

/* 
static char *path_home(char *command, char *path, int i)
{
    int j;

    path = ft_strdup(getenv("HOME"));
    j = strlen(path);
    i += 1;
    path[j] = '/';
    j++;
    while(command[++i])
    {
        path[j] = command[i];
        j++;
    }
    path[j] = '\0';
    return(path);
}

static char *path_slash(char *command, char *path, int i)
{
    int j;

    j = 0;
    path[j] = '/';
    j++;
    while(command[++i])
    {
        path[j] = command[i];
        j++;
    }
    path[j] = '\0';    
    return(path);
}

void cd(char *command, char *envp[])
{
    DIR*    dir;
    char    *path;
    int        i;
    char    *join;

    path = ft_strdup(getenv("HOME"));
    i = 2;
    while(command[i])
    {
        if(command[i] == '\t' || command[i] == ' ')
            i++;
        if(command[i] == '~')
        {
            path = path_home(command, path, i);
            break;
        }
        if(command[i] == '/')
        {
            path = path_slash(command, path, i);
            break;
        }
        i++;
    }
    dir = opendir(path);
    if (!dir)
        exit(89);

    chdir(path);

    i = -1;
    while (envp[++i])
    {
        if (!ft_strncmp(envp[i], "PWD", 3))
        {
            join = ft_strjoin(ft_strdup("PWD="), path);
            envp[i] = ft_strdup(join);    //dar free na envp no final
            free(join);
            break ;
        }
    }

    free(path);
    closedir(dir);
}
*/
