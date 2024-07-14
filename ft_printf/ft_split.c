/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreo <sreo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:08:44 by sreo              #+#    #+#             */
/*   Updated: 2024/05/10 16:28:13 by sreo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	stringcount(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static int	charcount(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	i++;
	return (i);
}

static int	stringset(char **strs, char const *s, char c)
{
	int	i;
	int	j;
	int	k;
	int	count;

	i = 0;
	k = 0;
	count = stringcount(s, c);
	while (i < count - 1)
	{
		j = -1;
		while (s[k] == c)
			k++;
		strs[i] = (char *)malloc(sizeof(char) * charcount(&s[k], c));
		if (strs[i] == NULL)
			return (1);
		while (++j < charcount(&s[k], c) - 1)
			strs[i][j] = s[k + j];
		k += j;
		strs[i][j] = '\0';
		i++;
	}
	strs[i] = NULL;
	return (0);
}

static void	allfree(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		judge;

	judge = 0;
	strs = (char **)malloc(sizeof(char *) * stringcount(s, c));
	if (strs == NULL)
		return (NULL);
	judge = stringset(strs, s, c);
	if (judge)
	{
		allfree(strs);
		free(strs);
		return (NULL);
	}
	return (strs);
}
