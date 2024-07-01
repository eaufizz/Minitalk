/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:41:35 by sreo              #+#    #+#             */
/*   Updated: 2024/05/19 01:02:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	int i;
	int count;
	
	i = 0;
	count = 0;
	va_list args;
	va_start(args, format);
	while(format[i])
	{
		if(format[i] == '%' && format[i + 1])
		{
			if(format[i + 1] == '%')
				count += ft_putchr(format[++i]);
			else
				count += format_processor(format[++i], args);
		}
		else
			count += ft_putchr(format[i]);
		i++;
	}
	return count;
}
