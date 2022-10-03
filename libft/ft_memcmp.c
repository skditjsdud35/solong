/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunahn <sunahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:53:27 by sunahn            #+#    #+#             */
/*   Updated: 2022/03/26 17:14:13 by sunahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*us1;
	unsigned char	*us2;
	size_t			i;

	i = 0;
	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	while (n--)
	{
		if (*us1 != *us2)
			return (*us1 - *us2);
		us1++;
		us2++;
	}
	return (0);
}
