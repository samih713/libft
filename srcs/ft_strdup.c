/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:29:45 by sabdelra          #+#    #+#             */
/*   Updated: 2022/11/26 14:21:00 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	size;
	size_t	i;
	char	*result;

	i = 0;
	size = ft_strlen(s1) + 1;
	result = (char *)malloc(size);
	if (!result)
		return (NULL);
	while (i < size)
	{
		result[i] = s1[i];
		i++;
	}
	return (result);
}
