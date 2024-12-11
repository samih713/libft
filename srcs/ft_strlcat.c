/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:08:22 by sabdelra          #+#    #+#             */
/*   Updated: 2022/11/27 18:23:18 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		j;
	int		length;

	if (!dst && !size)
		return (0);
	length = ft_strlen((const char *)dst);
	if (size <= ft_strlen((const char *)dst))
		return (size + ft_strlen(src));
	i = ft_strlen((const char *)dst);
	j = 0;
	while (src[j] != '\0' && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (length + ft_strlen(src));
}
/* int main(void)
{
	char dest[100];
	printf("%zu\n", ft_strlcat(dest, "lorem", 15));
	printf("%zu\n", strlcat(dest, "lorem", 15));
}
 */
