/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:47:58 by sabdelra          #+#    #+#             */
/*   Updated: 2022/12/01 18:21:49 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	size_t	length;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	length = ft_strlen(s1) + ft_strlen(s2) + 1;
	string = (char *)malloc(length);
	if (!string)
		return (NULL);
	i = 0;
	while (*s1 && i < length)
	{
		string[i] = *s1;
		s1++;
		i++;
	}
	while (*s2 && i < length)
	{
		string[i] = *s2;
		s2++;
		i++;
	}
	string[i] = '\0';
	return (string);
}
