/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:46:38 by noalexan          #+#    #+#             */
/*   Updated: 2022/04/01 11:42:40 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy(char *src, char *copy)
{
	int	i;

	i = -1;
	while (src[++i])
		copy[i] = src[i];
	copy[i] = '\0';
	return (copy);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*copy;

	i = 0;
	while (src[i])
		i++;
	copy = malloc(i * sizeof(char));
	ft_strcpy(src, copy);
	return (copy);
}
