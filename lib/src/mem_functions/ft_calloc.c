/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 00:25:51 by jlucas-s          #+#    #+#             */
/*   Updated: 2022/10/12 22:16:05 by jlucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb && (nmemb * size) / size != nmemb)
		return (0);
	if (!nmemb || !size)
		return (0);
	ptr = (void *)malloc(nmemb * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

/*
#include <stdio.h>
#include "ft_bzero.c"
#include "ft_memset.c"
int main(void)
{
	char * str = "hello World";
	printf("%s\n", str);
	str = calloc(11, sizeof(char));
	printf("%s\n", str);
	return 0;
}
*/