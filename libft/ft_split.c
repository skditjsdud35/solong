/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunahn <sunahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:05:57 by sunahn            #+#    #+#             */
/*   Updated: 2022/03/31 16:14:15 by sunahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_len(char const *str, char charset)
{
	int	i;

	i = 0;
	while (*str && *str != charset)
	{
		str++;
		i++;
	}
	return (i);
}

int	get_count(char const *str, char charset)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != charset)
		{	
			count++;
			while (str[i] && str[i] != charset)
				i++;
			if (!str[i])
				break ;
		}
		i++;
	}
	return (count);
}

char	**ft_free_all(char **str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		idx;
	int		len;

	if (!s)
		return (0);
	result = (char **)malloc(sizeof(char *) * (get_count(s, c) + 1));
	if (!result)
		return (0);
	idx = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			len = get_len(s, c);
			result[idx] = (char *)malloc(len + 1);
			if (!result[idx])
				return (ft_free_all(result));
			ft_strlcpy(result[idx++], s, len + 1);
			s += len - 1;
		}
		s++;
	}
	result[idx] = 0;
	return (result);
}
