/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchchan <atchchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 19:18:49 by atchchan          #+#    #+#             */
/*   Updated: 2026/09/09 23:12:45 by atchchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countword(char const *s, char c)
{
	char	ctos[2];
	char	*p;
	size_t	i;
	int		count;

	if (!(*s))
		return (0);
	ctos[0] = c;
	ctos[1] = '\0';
	p = ft_strtrim(s, ctos);
	if (!p)
		return (-1);
	count = 0;
	i = 0;
	while (p[i])
	{
		if (p[i] == c)
			count++;
		while (p[i] == c)
			i++;
		i++;
	}
	free(p);
	return (count + 1);
}

static void	splitter(char const *s, char c, char **p, int cw)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	j = 0;
	while (s[i])
	{
		count = 0;
		while (s[i] != c && s[i])
		{
			count++;
			i++;
		}
		if (count != 0 && j < (size_t)cw + 1)
		{
			(p)[j] = ft_substr(s, i - count, count);
			j++;
		}
		if (s[i])
			i++;
	}
	(p)[j] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		cw;

	cw = countword(s, c);
	if (cw == -1)
		return (NULL);
	p = malloc(sizeof(char *) * (cw + 1));
	if (!p)
		return (NULL);
	splitter(s, c, p, cw);
	return (p);
}
