/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:04:51 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/15 15:30:49 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	word_count(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static int	word_len(const char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static int	save_words(char **array, const char *s, char c, int arr_i)
{
	int	len;
	int	j;

	while (*s)
	{
		while (*s && s[0] == c)
			s++;
		if (!(*s))
			return (1);
		len = word_len(s, c);
		array[arr_i] = malloc((len + 1) * sizeof(char));
		if (!array[arr_i])
			return (0);
		j = 0;
		while (j < len)
		{
			array[arr_i][j] = s[j];
			j++;
		}
		array[arr_i][j] = '\0';
		arr_i++;
		s += len;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**array;

	if (!s)
		return (0);
	words = word_count(s, c);
	array = malloc((words + 1) * sizeof(char *));
	if (!array)
		return (0);
	save_words(array, s, c, 0);
	array[words] = NULL;
	return (array);
}
