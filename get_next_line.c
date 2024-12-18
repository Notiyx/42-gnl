/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlonghin <tlonghin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:37:37 by tlonghin          #+#    #+#             */
/*   Updated: 2024/12/18 02:58:38 by tlonghin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_files(int fd, char *buffer)
{
	char	*tmp;
	int		bytes_read;

	bytes_read = 1;
	if (!buffer)
		buffer = ft_calloc(1, 1);
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer || !tmp)
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
		buffer = ft_strjoin(buffer, tmp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(tmp);
	return (buffer);
}

char	*set_lines(char *buffer)
{
	char	*lines;
	size_t	i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	lines = ft_calloc((i + 1), sizeof(char));
	if (!lines)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		lines[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		lines[i++] = '\n';
	lines[i] = '\0';
	return (lines);
}

char	*clear_data(char *buffer)
{
	int		i;
	int		j;
	char	*n_buff;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	n_buff = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	if (!n_buff)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		n_buff[j++] = buffer[i++];
	n_buff[j] = 0;
	free(buffer);
	return (n_buff);
}

char	*get_next_line(int fd)
{
	static char	*buffer = 0;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		buffer = 0;
		return (NULL);
	}
	buffer = read_files(fd, buffer);
	if (!buffer)
		return (NULL);
	line = set_lines(buffer);
	if (!line)
	{
		free(buffer);
		buffer = 0;
		return (NULL);
	}
	buffer = clear_data(buffer);
	return (line);
}

/* int main(void)
{
	int fd;
	int i;
	char *line;
	i = 0;
	fd = open("ff", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("line %02d: %s", i++, line);
		free(line);
	}
	close(fd);
} */
