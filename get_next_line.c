/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noahalexandre <noahalexandre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:15:07 by noahalexand       #+#    #+#             */
/*   Updated: 2022/04/14 12:02:07 by noahalexand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_reverse_split(char **stack, char *save)
{
	int		size;
	int		i;
	int		j;
	int		k;
	char	*line;

	size = 0;
	i = -1;
	k = -1;
	while (stack[++i])
		size += ft_strlen(stack[i]);
	line = malloc((size + ft_strlen(save) + 1) * sizeof(char));
	i = -1;
	while (save[++k])
		line[k] = save[k];
	while (stack[++i])
	{
		j = -1;
		while (stack[i][++j])
			line[k++] = stack[i][j];
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		**stack;
	char		*line;

	printf("GET_NEXT_LINE has started\n");
	if (BUFFER_SIZE < 1)
		return (NULL);
	save = malloc(BUFFER_SIZE * sizeof(char));
	stack = ft_getstack(fd, &save);
	line = ft_reverse_split(stack, save);
	return (line);
}
