/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlonghin <tlonghin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:37:43 by tlonghin          #+#    #+#             */
/*   Updated: 2024/12/03 03:46:06 by tlonghin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	sto = (ft_strlen(s1) + ft_strlen(s2));
	join = malloc(sto + 1);
	if (!join || !s1 || !s2)
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

char	*ft_calloc(size_t lenght, size_t multi)
{
	char	*call;	
	size_t	i;

	i = 0;
	call = malloc(lenght * multi);
	if (!call)
		return (NULL);
	while (i < (lenght * multi))
		call[i++] = 0;
	return (call);
}
