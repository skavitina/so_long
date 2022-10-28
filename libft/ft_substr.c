/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 21:09:32 by tpeggie           #+#    #+#             */
/*   Updated: 2021/11/12 16:52:05 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const	*s, unsigned int start, size_t len)
{
	size_t			j;
	char			*dest;
	unsigned int	len_s;

	j = 0;
	if (!s)
		return (0);
	len_s = ft_strlen(s);
	if (len_s < start)
		len = 0;
	else if (len > (len_s + 1))
		len = len_s;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (0);
	while (j < len)
	{
		dest[j] = s[start + j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
