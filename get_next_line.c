/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlonghin <tlonghin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 09:31:07 by tlonghin          #+#    #+#             */
/*   Updated: 2024/11/27 13:35:50 by tlonghin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*set_lines(char	*line, size_t start, char *buffer)
{
	size_t	j;

	j = 0;
	line = malloc(sizeof(char) * (start + 1));
	if (!line)
		return (NULL);
	while (buffer[j] && j < start)
	{
		line[j] = buffer[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*read_file(int fd, char *tmp, char *buff, size_t bytes_rd)
{
	size_t	i;
	char	*line;

	i = 0;
	while (!ft_strchr(buff, '\n'))
	{
		bytes_rd = read(fd, tmp, BUFFER_SIZE);
		if (bytes_rd <= 0)
			break ;
		tmp[bytes_rd] = '\
		buff = ft_strjoin(buff, tmp);
	}
	
	if (!buff || !buff[0])
	{
		free(buff);
		return (NULL);
	}
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		i++;
	line = set_lines(line, i, buff);
	if (!line)
		return (NULL);
	return (line);
}

char	*clean_buff(char *tmp)
{
	size_t	i;

	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (tmp[i] == '\n')
		i++;
	return (tmp + i);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	size_t		bytes_rd;
	char		*tmp;
	char		*line;

	bytes_rd = 0;
	if (fd < 0)
		return (NULL);
	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	if (!buff)
	{
		buff = malloc(BUFFER_SIZE + 1);
		if (!buff)
			return (NULL);
	}
	line = read_file(fd, tmp, buff, bytes_rd);
	buff = clean_buff(tmp);
	//free_data(tmp);
	return (line);
}

int	main(void)
{
	int	fd;
	int	i;

	i = 0;
	fd = open("file.txt", O_RDONLY);
/* 	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd); */
	printf("lines 1 : %s", get_next_line(fd));
	printf("lines 2 : %s", get_next_line(fd));
	printf("lines 3 : %s", get_next_line(fd));
	printf("lines 4 : %s", get_next_line(fd));
	printf("lines 5 : %s", get_next_line(fd));
	printf("lines 6 : %s", get_next_line(fd));
	printf("lines 7 : %s", get_next_line(fd));
	printf("lines 8 : %s", get_next_line(fd));
	printf("lines 9 : %s", get_next_line(fd));
	printf("lines 10 : %s", get_next_line(fd));
	printf("lines 12 : %s", get_next_line(fd));
	printf("lines 13 : %s", get_next_line(fd));
	printf("lines 14 : %s", get_next_line(fd));
	printf("lines 15 : %s", get_next_line(fd));
	printf("lines 16 : %s", get_next_line(fd));
	printf("lines 17 : %s", get_next_line(fd));
	printf("lines 18 : %s", get_next_line(fd));
	printf("lines 19 : %s", get_next_line(fd));
}
