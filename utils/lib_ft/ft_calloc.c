/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelena- <ghelena-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:21:08 by ghelena-          #+#    #+#             */
/*   Updated: 2023/10/26 16:30:52 by ghelena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../so_long.h"

void	*ft_calloc(size_t	nmemb, size_t	size)
{
	size_t	memsize;
	char	*alloc;
	size_t	i;
	size_t	n;

	if ((nmemb * size != 0) && ((nmemb * size) / size != nmemb))
		return (NULL);
	memsize = nmemb * size;
	alloc = (void *)malloc(memsize);
	if (!alloc)
		return (NULL);
	n = nmemb;
	i = 0;
	while (n-- > 0)
		alloc[i++] = '\0';
	return (alloc);
}
