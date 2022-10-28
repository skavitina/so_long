/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 22:28:36 by tpeggie           #+#    #+#             */
/*   Updated: 2021/11/12 16:54:12 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_znak(int n)
{
	if (n < 0)
		return (-1);
	else
		return (1);
}

static int	ft_len_num(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count = 1;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		count;
	char	*str;
	int		znak;

	count = ft_len_num(n) + (n < 0);
	znak = ft_znak(n);
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (str == NULL)
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	str[count] = '\0';
	while (n != 0)
	{
		str[--count] = (char)((n % 10) * znak + '0');
		n = n / 10;
	}
	count--;
	if (znak < 0)
		str[count] = '-';
	return (str);
}
