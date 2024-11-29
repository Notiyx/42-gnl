/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlonghin <tlonghin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 21:13:04 by tlonghin          #+#    #+#             */
/*   Updated: 2024/11/29 02:01:15 by tlonghin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_data(char	*buff, char *tmp)
{
	if (buff[0])
		free(buff);
	if (tmp[0])
		free(tmp);
}

char	*set_lines(char *line, char *buff)
{
	size_t	i;
	size_t	end;

	end = 0;
	i = 0;
	if (!buff)
		return (NULL);
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
	if (!buff)
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	i++;
	return (buff + i);
}

char	*read_files(int fd, char *tmp, char *buff)
{
	size_t	bytes_read;
	char	*n_buff;

	n_buff = buff;
	bytes_read = 0;
	while (!ft_strchr(n_buff, '\n'))
	{
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		if (bytes_read <= 0 || !n_buff)
			break ;
		tmp[bytes_read] = '\0';
		n_buff = ft_strjoin(n_buff, tmp);
	}
	if (bytes_read < 1 && n_buff[0] == '\0')
	{
		free_data(n_buff, tmp);
		return (NULL);
	}
	return (n_buff);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;
	char		*tmp;

	line = 0;
	if (!buff)
		buff = malloc(BUFFER_SIZE + 1);
	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp || !buff || fd < 0 || BUFFER_SIZE < 1)
	{
		free_data(buff, tmp);
		return (NULL);
	}
	buff = read_files(fd, tmp, buff);
	if (!buff)
	{
		free(buff);
		return (NULL);
	}
	line = set_lines(line, buff);
	buff = clear_buff(buff);
	return (returned_data(line, buff, tmp));
}


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
	printf("lines 23 : %s", get_next_line(fd));
					
}
