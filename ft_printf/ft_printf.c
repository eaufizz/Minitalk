/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreo <sreo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:14:09 by sreo              #+#    #+#             */
/*   Updated: 2024/05/20 21:35:56 by sreo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	errorcheck(int *count, int value)
{
	if (value == -1)
		*count = -1;
	else
		*count += value;
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i] && count != -1)
	{
		if (format[i] == '%' && format[i + 1])
		{
			if (format[i + 1] == '%')
				errorcheck(&count, ft_putchr(format[++i]));
			else
				errorcheck(&count, format_processor(format[++i], args));
		}
		else
			errorcheck(&count, ft_putchr(format[i]));
		i++;
	}
	return (count);
}
