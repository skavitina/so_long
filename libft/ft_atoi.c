/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpeggie <tpeggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 21:17:40 by tpeggie           #+#    #+#             */
/*   Updated: 2021/11/12 22:13:02 by tpeggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	negative;
	int	nb;

	i = 0;
	negative = 0;
	nb = 0;
	while ((str[i] == '\t') || (str[i] == '\n') || (str[i] == '\v') \
	|| (str[i] == '\f') || (str[i] == '\r') || (str[i] == ' '))
		i++;
	if (str[i] == '-')
		negative = 1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10;
		nb = nb + ((int)str[i] - '0');
		i++;
	}
	if (negative == 1)
		return (-nb);
	else
		return (nb);
}
