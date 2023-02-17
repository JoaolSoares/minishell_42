/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:44:51 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/02/16 23:42:39 by jlucas-s         ###   ########.fr       */
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
            // free(envp[i]);   // Resolver essa pica
            envp[i] = ft_strdup(join);
            new_pwd[0] = 'a';
            free(join);
            break ;
        }
    }
}

char    *make_path(char *home_path, char *aux_path)
{
    char    *final_path;

    if(aux_path[0] == '~')
        final_path = ft_strjoin(ft_strjoin(home_path, "/"), aux_path + 2);
    else if(aux_path[0] == '/')
    {
        final_path = ft_strdup(aux_path);
        free(home_path);
    }

    return (final_path);
}

int cd(char *command, char *envp[])
{
    DIR*    dir;
    char    *path;
    int     i;

    i = 1;
    while(command[++i] == ' ') ;

    if((command[i] == '~' || command[i] == '/' ) && (ft_strlen(command) - i - 1) > 4)
        path = make_path(ft_strdup(getenv("HOME")), command + i);
    else
        path = ft_strdup(getenv("HOME"));

    dir = opendir(path);
    if (!dir)
    {
        ft_printf("-minishell: cd: %s: No such file or directory\n", path);
        free(path);
        return (1);
    }

    chdir(path);
    update_pwd(envp, path);

    free(path);
    closedir(dir);
    return (0);
}   
