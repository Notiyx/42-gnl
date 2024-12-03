/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlonghin <tlonghin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:37:37 by tlonghin          #+#    #+#             */
/*   Updated: 2024/12/03 03:47:49 by tlonghin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_set_data(char *buff, char *tmp)
{
	char	*new;

	new = ft_strjoin(buff, tmp);
	free(buff);
	return (new);
}

char	*read_files(int fd, char *buff)
{
	char	*tmp;
	int		bytes_read;

	bytes_read = 1;
	if (!buff)
		buff = ft_calloc(1, 1);
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (NULL);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[bytes_read] = '\0';
		buff = ft_set_data(buff, tmp);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(tmp);
	return (buff);
}

char	*set_lines(char *buff)
{
	char	*lines;
	size_t	i;

	i = 0;
	if (!buff[i])
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		i++;
	lines = ft_calloc((i + 1), sizeof(char));
	if (!lines)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		lines[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
		lines[i++] = '\n';
	lines[i] = '\0';
	return (lines);
}

char	*clear_data(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_files(fd, buffer);
	if (!buffer)
		return (NULL);
	line = set_lines(buffer);
	if (!line)
		return (NULL);
	buffer = clear_data(buffer);
	return (line);
}

/* 
int	main(void)
{
	int	fd;
	int	i;
	char	*line;
	i = 0;
	fd = open("file.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("line %02d: %s", i++, line);
		free(line);
	}
	close(fd);
} */