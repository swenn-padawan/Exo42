/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swenn <swenn@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:05:47 by swenn             #+#    #+#             */
/*   Updated: 2024/09/24 16:18:25 by swenn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_charset(char l, char *charset)
{
	char	*c;

	c = charset;
	while (*c)
	{
		if (l == *c)
			return (1);
		c++;
	}
	return (0);
}

int	count_word(char *str, char *charset)
{
	int		count;
	int		word;
	char	*s;

	count = 0;
	word = 0;
	s = str;
	while (*s)
	{
		if (!ft_is_charset(*s, charset) && !word)
		{
			word = 1;
			count++;
		}
		if (ft_is_charset(*s, charset) && word)
			word = 0;
		s++;
	}
	return (count);
}

char	*ft_strcpy(char *str, int start, int end)
{
	char	*s;
	int		i;

	s = malloc(end - start + 1);
	if (!s)
		return (NULL);
	i = 0;
	while (start < end)
	{
		s[i] = str[start];
		i++;
		start++;
	}
	s[i] = '\0';
	return (s);
}

int	*find_index(char *str, char *charset)
{
	int	i;
	int	j;
	int	*tab_index;

	i = 0;
	j = 0;
	tab_index = malloc(sizeof(int) * count_word(str, charset) * 2);
	if (!tab_index)
		return (0);
	while (str[i])
	{
		while (ft_is_charset(str[i], charset))
			i++;
		tab_index[j++] = i;
		while (!ft_is_charset(str[i], charset) && str[i])
			i++;
		tab_index[j++] = i;
	}
	return (tab_index);
}

char	**ft_split(char *str, char *charset)
{
	char	**split_str;
	int		i;
	int		j;
	int		*index;
	int		end;

	if (!str || !charset)
		return (NULL);
	split_str = malloc(sizeof(char *) * count_word(str, charset) + 1);
	if (!split_str)
		return (NULL);
	i = 0;
	j = 0;
	index = find_index(str, charset);
	while (i < count_word(str, charset) * 2)
	{
		end = index[i + 1];
		split_str[j] = ft_strcpy(str, index[i], end);
		i += 2;
		j++;
	}
	split_str[j] = NULL;
	return (split_str);
}

int main()
{
	char	**split;
	int	i;

	split = ft_split("ah voila aa a", " ");
	i = 0;
	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
}
