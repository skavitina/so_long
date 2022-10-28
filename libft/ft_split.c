/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 20:03:36 by tpeggie           #+#    #+#             */
/*   Updated: 2021/11/12 16:41:15 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char	*str, char delimiter)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != delimiter)
		{
			while (str[i] != delimiter && str[i + 1])
				i++;
			count++;
		}
		i++;
	}
	return (count);
}

static char	*ft_word(const char	*str, char c)
{
	int		i;
	char	*word;

	i = 0;
	while (*str && *str == c)
		str++;
	while (str[i] && str[i] != c)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**ft_free_words(int i, char **ptr)
{
	while (i > 0)
	{
		free(ptr[i - 1]);
		i--;
	}
	free(ptr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr_arr_words;
	int		words;
	int		i;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	ptr_arr_words = (char **)malloc(sizeof(char *) * (words + 1));
	if (ptr_arr_words == NULL)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*s && *s == c)
			s++;
		ptr_arr_words[i] = ft_word(s, c);
		if (ptr_arr_words[i] == NULL)
			return (ft_free_words(i, ptr_arr_words));
		while (*s && *s != c)
			s++;
		i++;
	}
	ptr_arr_words[i] = NULL;
	return (ptr_arr_words);
}
