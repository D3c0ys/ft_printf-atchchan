/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchchan <atchchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 13:27:40 by atchchan          #+#    #+#             */
/*   Updated: 2026/09/05 23:56:15 by atchchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ldst;
	size_t	i;

	if (!dst || !src)
		return (ft_strlen(src));
	ldst = ft_strlen(dst);
	if (size <= ldst)
		return (size + ft_strlen(src));
	i = 0;
	while (src[i] && i < size - ldst - 1)
	{
		dst[i + ldst] = src[i];
		i++;
	}
	dst[i + ldst] = 0x00;
	return (ldst + ft_strlen(src));
}
