/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 21:50:17 by tpeggie           #+#    #+#             */
/*   Updated: 2021/11/12 16:48:40 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;
	int		lens1;
	int		lens2;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen((char *)s1);
	lens2 = ft_strlen((char *)s2);
	str = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!str)
		return (NULL);
	while (i < lens1)
	{
		str[j++] = s1[i++];
	}
	i = 0;
	while (i < lens2)
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}
