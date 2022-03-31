/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:42:18 by noalexan          #+#    #+#             */
/*   Updated: 2022/03/31 15:39:39 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	readFile(int fd)
{
	unsigned char	buffer[10];
	int				bytes_read;
	int				k;

	k = 0;
	bytes_read = 0;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buffer, 10);
		k++;
		for(int i = 0; i < 10; i++)
			printf("%c", buffer[i]);
	}
}

char	*get_next_line(int fd)
{
	static int	index = 0;

	index++;
	printf("%d%d", index, fd);
	return ("c");
}

int	main(void)
{
	int	fd;

	fd = open("file.txt", O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	readFile(fd);
	close(fd);
	return (0);
}
