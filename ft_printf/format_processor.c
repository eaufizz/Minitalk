/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_processor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreo <sreo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:25:04 by sreo              #+#    #+#             */
/*   Updated: 2024/05/20 15:25:04 by sreo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_processor(char sign, va_list args)
{
	if (sign == 'c')
		return (ft_putchr(va_arg(args, int)));
	else if (sign == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (sign == 'p')
		return (ft_putptr(va_arg(args, unsigned long long)));
	else if (sign == 'd' || sign == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (sign == 'u')
		return (ft_uitoa(va_arg(args, unsigned int)));
	else if (sign == 'x' || sign == 'X')
		return (ft_itoh(va_arg(args, unsigned int), sign));
	return (0);
}
