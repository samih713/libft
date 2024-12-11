/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:42:53 by sabdelra          #+#    #+#             */
/*   Updated: 2022/11/27 17:02:02 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*string;
	unsigned int	i;

	string = (char *)s;
	i = 0;
	if (!s || !f)
		return (NULL);
	if ((ft_strlen(s) + 1) > (SIZE_MAX / sizeof(char *)))
		return (NULL);
	string = (char *)malloc((ft_strlen(s) + 1) * sizeof(*string));
	if (!string)
		return (NULL);
	while (s[i])
	{
		string[i] = f(i, s[i]);
		i++;
	}
	string[i] = '\0';
	return (string);
}
