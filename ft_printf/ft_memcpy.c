/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreo <sreo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:08:37 by sreo              #+#    #+#             */
/*   Updated: 2024/05/09 16:36:08 by sreo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *buf1, const void *buf2, size_t n)
{
	unsigned char	*p;
	unsigned char	*c;
	size_t			i;

	p = (unsigned char *)buf1;
	c = (unsigned char *)buf2;
	if (buf1 == NULL && buf2 == NULL)
		return (buf1);
	if (n <= 0)
		return (buf1);
	i = 0;
	while (i < n)
	{
		p[i] = c[i];
		i++;
	}
	return (buf1);
}
