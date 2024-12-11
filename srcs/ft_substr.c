/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:58:03 by sabdelra          #+#    #+#             */
/*   Updated: 2022/12/01 18:32:22 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_string;
	size_t	string_length;
	size_t	i;

	if (!s)
		return (NULL);
	string_length = ft_strlen(s);
	if (string_length < start)
		len = 0;
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	sub_string = (char *)malloc(len + 1);
	if (!sub_string)
		return (NULL);
	i = 0;
	while (i < len && (i + start) < string_length)
	{
		sub_string[i] = s[start + i];
		i++;
	}
	sub_string[i] = '\0';
	return (sub_string);
}
