/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzapata <dzapata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 17:40:13 by dzapata           #+#    #+#             */
/*   Updated: 2024/04/14 14:01:36 by dzapata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h" 

static int	count_words(char const *s, char c, int *i)
{
	int	words;
	int	j;

	if (s[0] == '\0')
		return (0);
	*i = 0;
	words = 1;
	while (s[*i] && s[*i] == c)
		(*i)++;
	if (!s[*i])
		return (0);
	j = *i;
	while (s[j])
	{
		if (s[j] == c && s[j + 1] && s[j + 1] != c)
			words++;
		j++;
	}
	return (words);
}

static char	*fill_word(char const *s, char c, int *i)
{
	int		len;
	int		j;
	char	*str;

	while (s[*i] && s[*i] == c)
		(*i)++;
	j = *i;
	len = 0;
	while (s[j] != c && s[j++])
		len++;
	str = (char *) malloc(len + 1);
	if (!str)
		return (NULL);
	j = -1;
	while ((++j) < len && s[*i])
	{
		str[j] = s[*i];
		(*i)++;
	}
	str[j] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		n_words;
	int		i;
	int		n;

	n_words = count_words(s, c, &i);
	strs = (char **) malloc((n_words + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	n = -1;
	while ((++n) < n_words)
	{
		strs[n] = fill_word(s, c, &i);
		if (!strs[n])
		{
			free_table((void **) strs);
			return (NULL);
		}
		i++;
	}
	strs[n] = NULL;
	return (strs);
}
