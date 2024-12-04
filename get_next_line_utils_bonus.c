/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlonghin <tlonghin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:37:43 by tlonghin          #+#    #+#             */
/*   Updated: 2024/12/04 02:08:08 by tlonghin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr(char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	sto;
	char	*join;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	sto = (ft_strlen(s1) + ft_strlen(s2));
	join = ft_calloc(sto + 1, sizeof(char));
	if (!join)
		return (NULL);
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j])
		join[i++] = s2[j++];
	join[i] = '\0';
	return (join);
}

void	ft_bzero(void *mem, size_t sz)
{
	while (sz--)
		*(unsigned char *)mem++ = 0;
}

void	*ft_calloc(size_t nmemb, size_t sz)
{
	void	*ptr;

	if (nmemb > 0 && sz > __SIZE_MAX__ / nmemb)
		return (0);
	ptr = malloc(nmemb * sz);
	if (ptr)
		ft_bzero(ptr, nmemb * sz);
	return (ptr);
}
