/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 20:41:49 by jlucas-s          #+#    #+#             */
/*   Updated: 2023/03/15 18:55:44 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// static void	print_env_var(char *var, t_node *env, int *return_value)
// {
// 	t_node	*aux;
// 	int		i;

// 	i = 0;
// 	if (var[0] == '?')
// 	{
// 		ft_printf("%i", *return_value);
// 		i++;
// 	}
// 	aux = env;
// 	while (aux)
// 	{
// 		if (!ft_strncmp(aux->content, var + i, ft_strlen(var) - i) && 
// 			ft_strlen(var + i) > 0)
// 		{
// 			ft_putstr_fd(ft_strchr(aux->content, '=') + 1, STDOUT_FILENO);
// 			break ;
// 		}
// 		aux = aux->next;
// 	}
// }

int	echo(char **command)
{
	int	have_n;
	int	i;

	have_n = 0;
	if (command[1] && !ft_strncmp(command[1], "-n", ft_strlen(command[1]) + 1))
		have_n = 1;
	i = 0 + have_n;
	while (command[++i])
	{
		ft_putstr_fd(command[i], STDOUT_FILENO);
		if (command[i] + 1)
			ft_putchar(' ');
	}
	if (!have_n)
		ft_putchar('\n');
	return (0);
}
