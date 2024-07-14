/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreo <sreo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:04:06 by sreo              #+#    #+#             */
/*   Updated: 2024/05/20 21:29:58 by sreo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_abs(int *n, long *nn, int *sign)
{
	*sign = 1;
	*nn = (long)*n;
	if (*nn < 0)
	{
		*sign = -1;
		*nn *= -1;
	}
}

static int	digit_count(long n, int sign)
{
	int	count;

	count = 1;
	while (1)
	{
		n /= 10;
		if (n == 0)
			break ;
		count++;
	}
	if (sign == -1)
		count++;
	return (count);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		sign;
	int		count;
	char	result[12];
	long	nn;

	ft_bzero(result, 12);
	ft_abs(&n, &nn, &sign);
	count = digit_count(nn, sign);
	if (sign == -1)
		result[0] = '-';
	while ((2 <= count && sign == -1) || (1 <= count && sign == 1))
	{
		result[--count] = (nn % 10) + '0';
		nn /= 10;
	}
	write(fd, &result, ft_strlen(result));
}
