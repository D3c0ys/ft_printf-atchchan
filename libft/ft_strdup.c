/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchchan <atchchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 00:58:09 by atchchan          #+#    #+#             */
/*   Updated: 2026/09/06 04:24:12 by atchchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	size;

	size = ft_strlen(s) + 1;
	p = malloc(size);
	if (!p)
		return (NULL);
	ft_strlcpy(p, s, size);
	return (p);
}
