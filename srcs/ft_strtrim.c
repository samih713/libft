/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:08:24 by sabdelra          #+#    #+#             */
/*   Updated: 2022/12/01 19:53:06 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	trim_length(char const *s1, char const *set, char **start);

static int		in_set(const char c, const char *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	length;
	char	*start;
	char	*trimmed;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	start = (char *)s1;
	length = trim_length(s1, set, &start);
	trimmed = (char *)ft_calloc(length + 1, sizeof(char));
	if (!trimmed)
		return (NULL);
	while (start[i] && i < length)
	{
		trimmed[i] = start[i];
		i++;
	}
	trimmed[i] = '\0';
	return (trimmed);
}

static int	in_set(const char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	trim_length(char const *s1, char const *set, char **start)
{
	size_t	set_length;
	size_t	trim_length;
	size_t	f;

	set_length = ft_strlen(set);
	trim_length = ft_strlen(s1);
	f = 0;
	while (in_set(s1[f], set))
	{
		f++;
		(*start)++;
	}
	if (trim_length == f)
		return (0);
	while (in_set(s1[trim_length - 1], set))
	{
		trim_length--;
	}
	trim_length -= f;
	return (trim_length);
}
