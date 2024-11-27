/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlonghin <tlonghin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 00:23:07 by tlonghin          #+#    #+#             */
/*   Updated: 2024/11/27 09:31:36 by tlonghin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strtrim_start(const char *str, char c)
{
	size_t	st;
	size_t	i;
	size_t	end;
	char	*nstr;

	st = 0;
	end = ft_strlen((char *)str);
	i = 0;
	while (str[st] && str[st] != c)
		st++;
	nstr = malloc(sizeof(char) * (end - st + 1));
	if (!nstr)
		return (NULL);
	while (i < st)
	{
		nstr[i] = str[i];
		i++;
	}
	nstr[i] = '\0';
	return (nstr);
}

int	ft_strchr(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*nstr;
	int		i;

	i = 0;
	nstr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!nstr)
	{
		free(nstr);
		return (NULL);
	}
	while (*s1)
		nstr[i++] = *s1++;
	while (*s2)
		nstr[i++] = *s2++;
	nstr[i] = '\0';
	return (nstr);
}
