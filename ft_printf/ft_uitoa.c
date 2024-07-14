/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreo <sreo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:28:27 by sreo              #+#    #+#             */
/*   Updated: 2024/05/20 15:28:27 by sreo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digit_count(unsigned int n)
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
	return (count);
}

int	ft_uitoa(unsigned int n)
{
	int		count;
	char	result[11];

	ft_bzero(result, 11);
	count = digit_count(n);
	while (1 <= count)
	{
		result[--count] = (n % 10) + '0';
		n /= 10;
	}
	count = ft_putstr(result);
	return (count);
}
