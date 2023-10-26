/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelena- <ghelena-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:20:39 by ghelena-          #+#    #+#             */
/*   Updated: 2023/10/26 16:30:33 by ghelena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../so_long.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	if (!s || *s == '\0')
		return (count);
	while (s[count] != '\0')
		count++;
	return (count);
}
