/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunahn <sunahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:06:06 by sunahn            #+#    #+#             */
/*   Updated: 2022/03/31 16:12:03 by sunahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_get_len(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		i++;
	}
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;
	int		minus;

	minus = 0;
	len = ft_get_len(n);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	result[len--] = 0;
	if (n < 0)
		minus = 1;
	while (len >= 0)
	{
		result[len--] = ft_abs(n % 10) + 48;
		n = ft_abs(n / 10);
	}
	if (minus == 1)
		result[0] = '-';
	return (result);
}
