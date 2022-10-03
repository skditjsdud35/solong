/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunahn <sunahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:48:55 by sunahn            #+#    #+#             */
/*   Updated: 2022/03/31 19:26:31 by sunahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*curr;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst)
	{
		curr = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = curr;
	}
	*lst = 0;
}
