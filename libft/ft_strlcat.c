/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpeggie <tpeggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:15:04 by tpeggie           #+#    #+#             */
/*   Updated: 2021/11/11 22:29:38 by tpeggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t	dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	dstlen = ft_strlen ((char *)dst);
	srclen = ft_strlen ((char *)src);
	i = 0;
	if (dstsize < dstlen + 1)
		return (dstsize + srclen);
	if (dstsize > dstlen + 1)
	{
		while (src[i] != '\0' && dstlen + 1 + i < dstsize)
		{
			dst[dstlen + i] = src[i];
			i++;
		}
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}
