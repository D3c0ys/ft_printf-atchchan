/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchchan <atchchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 19:14:57 by atchchan          #+#    #+#             */
/*   Updated: 2026/09/08 10:26:23 by atchchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// s1 -> str to be trim
// set -> str containing chars to be removed in the beginning & end

#include "libft.h"

static int	strsearch(char const *s1, char c)
{
	char	*p;

	p = (char *)s1;
	while (*p)
	{
		if (*p == c)
			return (1);
		p++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	size;
	size_t	i;
	size_t	f;

	size = ft_strlen(s1);
	if (size == 0)
		return (ft_calloc(1, 1));
	i = 0;
	while (strsearch(set, s1[i]) && i < size)
		i++;
	f = size - 1;
	while (strsearch(set, s1[f]) && f < size && f > i)
		f--;
	return (ft_substr(s1, i, f - i + 1));
}
