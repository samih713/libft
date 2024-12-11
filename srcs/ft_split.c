/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:54:48 by sabdelra          #+#    #+#             */
/*   Updated: 2022/12/01 18:34:22 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**array;
	char	*s_ptr;
	size_t	character_count;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	s_ptr = (char *)s;
	character_count = 0;
	array = (char **)ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!array)
		return (NULL);
	while (i < count_words(s, c))
	{
		while (*s_ptr == c)
			s_ptr++;
		character_count = 0;
		while (s_ptr[character_count] != c && s_ptr[character_count] != '\0')
			character_count++;
		array[i] = (char *)malloc(character_count + 1);
		ft_strlcpy(array[i++], (const char *)s_ptr, character_count + 1);
		s_ptr += character_count;
	}
	return (array);
}

static size_t	count_words(char const *s, char c)
{
	size_t	character_count;
	size_t	word_count;

	character_count = 0;
	word_count = 0;
	while (s[character_count])
	{
		if (s[character_count] == c)
			character_count++;
		else
		{
			while (s[character_count] != c && s[character_count])
				character_count++;
			word_count++;
		}
	}
	return (word_count);
}
/*
int main(void)
{
	char str[] = "asdfa";
	char d = 0;
	char **store = ft_split(str, d);
	for(int i = 0; i < 1; i++)
	{
		printf("%s\n", store[i]);
	}
}
 */
