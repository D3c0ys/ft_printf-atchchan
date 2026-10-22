/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchchan <atchchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 23:58:09 by atchchan          #+#    #+#             */
/*   Updated: 2026/10/23 00:54:53 by atchchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

# include <unistd.h>

int	ft_puthex(unsigned long n, int upper);
int	ft_putptr(void *p);
int	ft_putunbr(unsigned int n);
int	ft_putnbr(int n);
int	ft_putstr(char *s);

#endif
