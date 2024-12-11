/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:28:49 by sabdelra          #+#    #+#             */
/*   Updated: 2022/12/01 18:30:25 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*nxt;

	if (!lst || !*lst)
		return ;
	temp = *lst;
	if (*lst && del)
	{
		while (temp)
		{
			nxt = temp->next;
			ft_lstdelone(temp, del);
			temp = nxt;
		}
	}
	else
		return ;
	*lst = NULL;
}
