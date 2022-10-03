/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunahn <sunahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:02:45 by sunahn            #+#    #+#             */
/*   Updated: 2022/03/31 17:11:29 by sunahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	while (len-- > 0)
	{
		result[i] = s[start];
		i++;
		start++;
	}
	result[i] = 0;
	return (result);
}
