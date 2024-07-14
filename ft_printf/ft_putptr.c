/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreo <sreo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:14:44 by sreo              #+#    #+#             */
/*   Updated: 2024/05/20 21:36:58 by sreo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printptr(uintptr_t ptr)
{
	int		i;
	int		temp;
	char	nbr[20];

	ft_bzero(nbr, 20);
	i = 0;
	while (ptr != 0)
	{
		temp = ptr % 16;
		if (temp < 10)
			nbr[i] = temp + 48;
		else
			nbr[i] = temp + 87;
		ptr /= 16;
		i++;
	}
	temp = i;
	while (--i >= 0)
	{
		write(1, &nbr[i], 1);
	}
	return (temp);
}

int	ft_putptr(unsigned long long ptr)
{
	if (write(1, "0x", 2) == -1)
		return (-1);
	if (ptr == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (3);
	}
	return (printptr(ptr) + 2);
}
