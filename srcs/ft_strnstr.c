/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:55:34 by sabdelra          #+#    #+#             */
/*   Updated: 2022/11/29 21:20:32 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		little_len;

	i = 0;
	little_len = ft_strlen(little);
	if (!*little || big == little)
		return ((char *)big);
	while (len && big[i] && i <= (len - little_len))
	{
		if (big[i] == *little && ft_memcmp((big + i), little, little_len) == 0)
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int main()
{
	char haystack[30] = "aaabcabcd";
	char needle[10] = "aabc";

	printf("%s\n", ft_strnstr(haystack, "aaabc", 5));
}
 */
