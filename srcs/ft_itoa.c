/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 13:45:07 by sabdelra          #+#    #+#             */
/*   Updated: 2022/12/01 18:39:10 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	no_of_digits(int n);

char	*ft_itoa(int n)
{
	char		*n_string;
	size_t		digits;
	long		j;

	j = (long)n;
	digits = no_of_digits(n);
	if (j <= 0)
	{
		j *= -1;
		digits += 1;
	}
	n_string = (char *)malloc((digits + 1) * sizeof(*n_string));
	if (!n_string)
		return (NULL);
	n_string[0] = '-';
	if (j == 0)
		n_string[0] = '0';
	n_string[digits] = '\0';
	while (j)
	{
		digits--;
		n_string[digits] = (j % 10) + '0';
		j /= 10;
	}
	return (n_string);
}

static size_t	no_of_digits(int n)
{
	int		no_of_digits;
	long	j;

	j = (long)n;
	no_of_digits = 0;
	if (j == 0)
		return (0);
	if (j < 10 && j > 0)
		return (1);
	else if (j < 0)
		j *= -1;
	while (j > 0)
	{
		j /= 10;
		no_of_digits++;
	}
	return (no_of_digits);
}
