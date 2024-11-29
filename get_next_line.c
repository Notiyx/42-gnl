/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlonghin <tlonghin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 05:02:12 by tlonghin          #+#    #+#             */
/*   Updated: 2024/11/29 10:54:22 by tlonghin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*set_data_or_free(int type, char *buff, char *tmp, char *line)
{
	if (buff && type == 0)
		free(buff);
	if (tmp && type == 0)
		free(tmp);
	if (line && type == 0)
		free(line);
	if (!tmp && type == 1)
	{
		tmp = malloc(BUFFER_SIZE + 1);
		if (!tmp)
			return (set_data_or_free(0, buff, 0, line));
	}
	return (0);
}

char	*read_files(int fd, char *buff, char *tmp)
{
	size_t	bytes_read;
	char	*new_buff;
	
	bytes_read = 0;
	new_buff = buff;
	while (!ft_strchr(new_buff, '\n'))
	{
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		tmp[bytes_read] = '\0';
		new_buff = ft_strjoin(new_buff, tmp);
		if (!new_buff)
		{
			free(new_buff);
			return (NULL);
		}
	}
	if (bytes_read <= 0 && ft_strlen(new_buff) == 0)
	{
		return (NULL);
	}
	return (new_buff);
}

char	*set_lines(char *line, char *buff)
{
	size_t	i;
	size_t	end;

	end = 0;
	i = 0;
	while (buff[end] && buff[end] != '\n')
		end++;
	end++;
	line = malloc(sizeof(char) * (end + 1));
	if (!line)
		return (NULL);
	while (i < end)
	{
		line[i] = buff[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*clear_buff(char *buff)
{
	size_t	i;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	i++;
	return (buff + i);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*tmp;
	char		*line;

	tmp = malloc(BUFFER_SIZE + 1);
	line = 0;
	if (!tmp || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!buff)
	{
		buff = malloc(BUFFER_SIZE + 1);
		if (!buff)
			return (set_data_or_free(0, 0, tmp, 0));
	}
	buff = read_files(fd, buff, tmp);
	if (!buff)
		return (set_data_or_free(0, buff, tmp, 0));
	line = set_lines(line, buff);
	if (!line)
		return (set_data_or_free(0, buff, tmp, 0));
	buff = clear_buff(buff);
	if (!buff)
		return (set_data_or_free(0, buff, tmp, line));
	set_data_or_free(0, 0, tmp, 0);
	return (line);
}
/* 
int	main(void)
{
	int	fd;
	int	i;

	i = 0;
	fd = open("file.txt", O_RDONLY);
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
	printf("lines 20 : %s", get_next_line(fd));
	printf("lines 21 : %s", get_next_line(fd));
	printf("lines 22 : %s", get_next_line(fd));
	close(fd);
	printf("lines 23 : %s", get_next_line(fd));
} */