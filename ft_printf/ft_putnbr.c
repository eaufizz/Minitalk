/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreo <sreo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:25:52 by sreo              #+#    #+#             */
/*   Updated: 2024/05/20 15:25:52 by sreo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	int		count;
	char	*str;

	str = ft_itoa(nbr);
	if (str == NULL)
		return (-1);
	count = ft_putstr(str);
	free(str);
	return (count);
}
