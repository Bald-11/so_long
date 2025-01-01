/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:19:24 by yabarhda          #+#    #+#             */
/*   Updated: 2024/12/26 10:46:30 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	fill_string(char *str, long n, int len)
{
	str[len] = '\0';
	while (len)
	{
		len--;
		str[len] = (n % 10) + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*dest;
	int		len;
	long	temp_n;

	len = 0;
	temp_n = n;
	if (temp_n == 0)
		len++;
	while (temp_n != 0)
	{
		len++;
		temp_n /= 10;
	}
	if (n < 0)
		len = 1;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	fill_string(dest, n, len);
	return (dest);
}
