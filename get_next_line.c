/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:42:18 by noalexan          #+#    #+#             */
/*   Updated: 2022/04/01 11:44:25 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		ret;
	char	*gnl;

	ret = 1;
	gnl = malloc(BUFFER_SIZE * sizeof(char));
	ret = read(fd, gnl, BUFFER_SIZE);
	gnl[ret] = '\0';
	return (ft_strdup(gnl));
}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		printf("%s\n", get_next_line(fd));
		close(fd);
	}
	else
		printf("Veuillez entrer le nom du fichier en argument.\n");
	return (0);
}
