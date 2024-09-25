/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmedyns <anmedyns@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:25:01 by anmedyns          #+#    #+#             */
/*   Updated: 2024/08/29 16:32:07 by anmedyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*copy;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(src);
	copy = (char *)malloc(sizeof(char) * (len + 1));
	if (copy == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		j;
	char		*s2;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len + start > ft_strlen(s))
		len = ft_strlen(s + start);
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	if (s2 == NULL)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len && s[i])
		{
			s2[j++] = s[i];
		}
		i++;
	}
	s2[j] = '\0';
	return (s2);
}

size_t	get_words(char *s, char c)
{
	size_t	count;

	count = 0;
	if (s == NULL)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			++count;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (count);
}

char	**split(char *s, char c)
{
	size_t		i;
	size_t		len;
	char		**count;

	if (!s)
		return (0);
	i = 0;
	count = malloc(sizeof(char *) * (get_words(s, c) + 1));
	if (!count)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				++s;
			count[i++] = ft_substr(s - len, 0, len);
		}
		else
			++s;
	}
	count[i] = NULL;
	return (count);
}
