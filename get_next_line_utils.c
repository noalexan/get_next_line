/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noahalexandre <noahalexandre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:15:02 by noahalexand       #+#    #+#             */
/*   Updated: 2022/04/14 11:35:19 by noahalexand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	char	*a;
	char	*b;
	size_t	i;

	i = 0;
	a = (char *) destination;
	b = (char *) source;
	while (i < size)
	{
		a[i] = b[i];
		i++;
	}
	return (destination);
}

char	*ft_strdup(const char *source)
{
	char	*copy;

	copy = malloc(BUFFER_SIZE * sizeof(char));
	if (!copy)
		return (NULL);
	ft_memcpy(copy, source, BUFFER_SIZE);
	return (copy);
}

char	*ft_read_buffer(int fd)
{
	char	*buffer;

	buffer = malloc(BUFFER_SIZE * sizeof(char));
	read(fd, buffer, BUFFER_SIZE);
	return (ft_strdup(buffer));
}

int	there_is_a_end_of_line(char *stack, char ***save)
{
	int	i;
	int	j;

	j = 0;
	i = -1;
	while (stack[++i])
	{
		if (stack[i] == '\n')
		{
			printf("END OF LINE\n");
			while (stack[++i] && i < BUFFER_SIZE)
			{
				printf("PUT '%c' TO save[%i]\n", stack[i], j);
				**save[j++] = stack[i];
			}
			return (1);
		}
		else if (stack[i] == '\0')
			return (1);
	}
	return (0);
}

char	**ft_getstack(int fd, char **save)
{
	char	**stack;
	int		i;

	printf("GETSTACK has started\n");
	i = 0;
	stack = malloc(2 * sizeof(char *));
	stack[i] = ft_read_buffer(fd);
	printf("READ : \"%s\"\n", stack[i]);
	while (!there_is_a_end_of_line(stack[i], &save))
	{
		i++;
		stack[i] = ft_read_buffer(fd);
		printf("READ : \"%s\"\n", stack[i]);
	}
	printf("GETSTACK has ended\n");
	return (stack);
}
