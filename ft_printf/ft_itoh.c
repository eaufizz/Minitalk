/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreo <sreo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 21:34:37 by sreo              #+#    #+#             */
/*   Updated: 2024/05/20 21:34:37 by sreo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_itoh(unsigned int nbr, char sign)
{
	int		i;
	int		temp;
	char	str[11];

	ft_bzero(str, 11);
	i = 0;
	while (nbr != 0 || i == 0)
	{
		temp = nbr % 16;
		if (temp < 10)
			str[i] = temp + 48;
		else if (sign == 'x')
			str[i] = temp + 87;
		else if (sign == 'X')
			str[i] = temp + 55;
		nbr /= 16;
		i++;
	}
	temp = i;
	while (--i >= 0)
		if (write(1, &str[i], 1) == -1)
			return (-1);
	return (temp);
}
