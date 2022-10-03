/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunahn <sunahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:37:45 by sunahn            #+#    #+#             */
/*   Updated: 2022/03/31 16:42:15 by sunahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*ret;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	start = (char *)s1;
	while (*start && ft_strchr(set, *start))
		start++;
	end = (char *)s1 + ft_strlen(s1);
	while (end > start && ft_strchr(set, *(end - 1)))
		end--;
	ret = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!ret)
		return (0);
	ft_strlcpy(ret, start, end - start + 1);
	return (ret);
}
