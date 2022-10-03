/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunahn <sunahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:49:13 by sunahn            #+#    #+#             */
/*   Updated: 2022/03/31 19:23:09 by sunahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *list, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*temp;

	if (list == 0 || f == 0)
		    return (NULL);
	result = NULL;
	while (list)
	{
		temp = ft_lstnew((*f)(list->content));
		if (!temp)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, temp);
		list = list->next;
	}
	return (result);
}	
