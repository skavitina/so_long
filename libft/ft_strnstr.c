/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpeggie <tpeggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 18:32:46 by tpeggie           #+#    #+#             */
/*   Updated: 2021/11/11 22:31:31 by tpeggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*haystack, const char	*needle, size_t	len)
{
	size_t	needle_len;
	size_t	i;

	i = 0;
	needle_len = ft_strlen((char *)needle);
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && (len > 0) && (i <= len - needle_len))
	{
		if (ft_strncmp(haystack, needle, needle_len) == 0)
			return ((char *)haystack);
		haystack++;
		i++;
	}
	return (NULL);
}
