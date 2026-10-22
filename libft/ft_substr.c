/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchchan <atchchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 01:43:50 by atchchan          #+#    #+#             */
/*   Updated: 2026/09/06 03:46:43 by atchchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	char	*si;
	char	*p;

	size = ft_strlen(s);
	if (len == 0 || start > size)
		return (ft_calloc(1, 1));
	if (size - start < len)
		len = size - start;
	si = (char *)s + start;
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	ft_strlcpy(p, si, len + 1);
	return (p);
}
