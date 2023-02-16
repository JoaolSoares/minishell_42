/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_01.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:44:51 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/02/15 22:59:00 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void cd(char *command, char *envp[])
{
    DIR*    dir;
    char    *path;
    int        i;
    char    *join;

    if (ft_strlen(command) == 2)    // Quando tem ' ' na frente do cd da merda ARRUMAR e arrumar conodições ~ ~/
        path = ft_strdup(getenv("HOME"));


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
