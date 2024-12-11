/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:30:16 by sabdelra          #+#    #+#             */
/*   Updated: 2022/11/26 16:28:54 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*chunk;
	size_t	i;

	i = 0;
	if (size && count > (SIZE_MAX / size))
		return (NULL);
	chunk = (char *)malloc(size * count);
	if (!chunk)
		return (NULL);
	while (i < count * size)
	{
		chunk[i] = 0;
		i++;
	}
	return ((void *)chunk);
}

/* #include <stdio.h>

int main(void)
{
	char *s = "Hello";
	char *p;
	p = (char *)ft_calloc(SIZE_MAX,SIZE_MAX);

	int i = 0;
	while(i < 6)
	{
		p[i] = s[i];
		i++;
	}
	i[p] = '\0';
	printf("%s\n", p);
}
 */
