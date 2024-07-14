/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreo <sreo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:28:40 by sreo              #+#    #+#             */
/*   Updated: 2024/05/09 16:24:06 by sreo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *buf1, const void *buf2, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	*c;

	c = (unsigned char *)buf2;
	p = (unsigned char *)buf1;
	i = -1;
	if (!buf1 && !buf2)
		return (NULL);
	if (p > c && p < c + n)
		while (++i < n)
			p[n - i - 1] = c[n - i - 1];
	else
		while (++i < n)
			p[i] = c[i];
	return (buf1);
}
