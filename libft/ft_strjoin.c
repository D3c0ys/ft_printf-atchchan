/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchchan <atchchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 04:43:02 by atchchan          #+#    #+#             */
/*   Updated: 2026/09/06 05:48:46 by atchchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s;
	char	*str;
	char	*p;
	size_t	i;

	s = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(s);
	if (!str)
		return (NULL);
	p = (char *)s1;
	i = 0;
	if (!(*s1))
		p = (char *)s2;
	while (*p)
	{
		str[i] = *p;
		p++;
		i++;
		if (!(*p) && i != s - 1)
			p = (char *)s2;
	}
	str[i] = 0x00;
	return (str);
}
