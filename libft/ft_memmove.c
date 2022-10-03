/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunahn <sunahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:49:22 by sunahn            #+#    #+#             */
/*   Updated: 2022/03/24 21:10:11 by sunahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*new_dst;
	unsigned char	*new_src;

	new_dst = (unsigned char *)dst;
	new_src = (unsigned char *)src;
	if (dst == src || len == 0)
		return (dst);
	if (dst < src)
		while (len--)
			*new_dst++ = *new_src++;
	else
		while (len--)
			*(new_dst + len) = *(new_src + len);
	return (dst);
}	
