/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:44:51 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/02/21 17:45:34 by jlucas-s         ###   ########.fr       */
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
            ft_strlcpy(envp[i], join, ft_strlen(join) + 1);
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

char *take_dots(int dot, char *path, char *pwd_path)
{
    char *final_path;

    if(dot == 1)
        final_path = ft_strjoin(pwd_path, path + 1);
    if(dot == 2)
        final_path = ft_strjoin(pwd_path, path + 2); // arrumar para apagar o ultimo diretorio de pwd_path, ou seja se por ex.
                                                    // pwd_path = "/home/douglas" vai se tornar só "/home" para em seguida concatenar 
                                                   // com "path + 2", pwd_path = "caminho_do_diretorio_pai_do_diretorio_atual/home"
    return(final_path);
}

int cd(char *command, char *envp[])
{
    DIR*    dir;
    char    *path;
    int     i;
    int     dot;
    char    *path_dot;

    i = 1;
    dot = 0;
    while(command[++i] == ' ') ;
    if((command[i] == '~' || command[i] == '/' ) && (ft_strlen(command) - i - 1) > 4)
        path = make_path(ft_strdup(getenv("HOME")), command + i);
    else if (!ft_strncmp(command + i, "~", 2) || !ft_strncmp(command + i, "~/", 3))
        path = ft_strdup(getenv("HOME"));
    else if (command[i] == '/')
        path = ft_strdup(command + i);
    else if ((command[i] == '.' && command[i + 1] != '.') || (command[i] == '.' && command[i + 1] == '/'))
    {
        path = ft_strdup(command + i);
        dot = 1;
    }
    else if ((command[i] == '.' && command[i + 1] == '.') || (command[i] == '.' && command[i + 1] == '.' && command[i + 2] == '/'))
    {
        path = ft_strdup(command + i);
        dot = 2;
    }
    else 
        path = ft_strdup(getenv("HOME"));

    dir = opendir(path);
    if (!dir)
    {
        ft_printf("minishell: cd: %s: No such file or directory\n", path);
        free(path);
        return (1);
    }
    chdir(path);
    path_dot = take_dots(dot, path, ft_strdup(getenv("PWD")));
    if(dot == 1 || dot == 2)
        update_pwd(envp, path_dot);
    else 
        update_pwd(envp, path);
    free(path);
    closedir(dir);
    return (0);
}   


/*
static void    update_pwd(char *envp[], char *new_pwd)
{
    int     i;
    char    *join;

    i = -1;
    while (envp[++i])
    {
        if (!ft_strncmp(envp[i], "PWD=", 4))
        {
            if (new_pwd[0] != '/')
                join = ft_strjoin(ft_strjoin(ft_strdup("PWD="), "/"), new_pwd);
            else
                join = ft_strjoin(ft_strdup("PWD="), new_pwd);
            if (join[ft_strlen(join) - 1] == '/')
                join[ft_strlen(join) - 1] = 0;
            // free(envp[i]);   // Resolver essa pica
            envp[i] = ft_strdup(join);
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

// void take_dots(char *path)
// {

    
// }

int cd(char *command, char *envp[])
{
    DIR*    dir;
    char    *path;
    int     i;

    i = 1;
    while(command[++i] == ' ') ;

    if((command[i] == '~' || command[i] == '/' ) && (ft_strlen(command) - i - 1) > 4)
        path = make_path(ft_strdup(getenv("HOME")), command + i);
    else if (!ft_strncmp(command + i, "~", 2) || !ft_strncmp(command + i, "~/", 3) \
            || !ft_strncmp(command + i, "", 1))
        path = ft_strdup(getenv("HOME"));
    else
        path = ft_strdup(command + i);

    dir = opendir(path);
    if (!dir)
    {
        ft_printf("-minishell: cd: %s: No such file or directory\n", path);
        free(path);
        return (1);
    }

    chdir(path);
    
    // take_dots(path);
    
    update_pwd(envp, path);

    free(path);
    closedir(dir);
    return (0);
}   
*/
