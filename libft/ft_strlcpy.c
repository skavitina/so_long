/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpeggie <tpeggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 18:32:29 by tpeggie           #+#    #+#             */
/*   Updated: 2021/11/11 22:29:46 by tpeggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t	dstsize)
{
	size_t	len;

	len = 0;
	if (dstsize > 0)
	{
		while (src[len] && len < (dstsize - 1))
		{
			dst[len] = src[len];
			len++;
		}
		dst[len] = 0;
	}
	while (src[len])
		len++;
	return (len);
}
