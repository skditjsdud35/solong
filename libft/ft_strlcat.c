/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunahn <sunahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:41:34 by sunahn            #+#    #+#             */
/*   Updated: 2022/03/31 19:37:27 by sunahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize <= dst_len)
		return (src_len + dstsize);
	while (*dst && i < dstsize)
	{
		i++;
		dst++;
	}
	while (*src && i + 1 < dstsize)
	{
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	if (i < dstsize)
		*dst = 0;
	return (src_len + dst_len);
}
