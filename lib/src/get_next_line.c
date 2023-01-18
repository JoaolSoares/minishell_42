/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:17:31 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/11/21 18:58:06 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_get_content(int fd, char *content)
{
	char	*buff;
	int		index;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	index = 1;
	while (ft_strchr(content, '\n') == 0 && index != 0)
	{
		index = read(fd, buff, BUFFER_SIZE);
		if (index == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[index] = 0;
		content = ft_strjoin(content, buff);
	}
	free(buff);
	return (content);
}

static char	*ft_get_line(char *content)
{
	char	*line;
	size_t	i;

	if (!content[0])
		return (NULL);
	i = ft_strlen_until(content, '\n');
	line = (char *)malloc(sizeof(char) * (i + 2));
	i = 0;
	while (content[i])
	{
		line[i] = content[i];
		if (content[i] == '\n')
		{
			++i;
			break ;
		}
		++i;
	}
	line[i] = 0;
	return (line);
}

static char	*ft_del_usedcontent(char *content)
{
	int		i;
	char	*new_content;
	int		count;

	i = ft_strlen_until(content, '\n');
	if (!content[i])
	{
		free(content);
		return (NULL);
	}
	new_content = (char *)malloc(sizeof(char) * (ft_strlen(content) - i + 1));
	if (!new_content)
		return (NULL);
	++i;
	count = 0;
	while (content[i])
		new_content[count++] = content[i++];
	new_content[count] = 0;
	free(content);
	return (new_content);
}

char	*get_next_line(int fd)
{
	static char	*content;
	char		*line;

	if (fd == -1)
	{
		free(content);
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	content = ft_get_content(fd, content);
	if (!content)
		return (NULL);
	line = ft_get_line(content);
	content = ft_del_usedcontent(content);
	return (line);
}
