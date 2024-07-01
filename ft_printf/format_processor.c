/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_processor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 23:44:44 by marvin            #+#    #+#             */
/*   Updated: 2024/05/16 23:44:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int format_processor(char sign, va_list args)
{
    if(sign == 'c')
        return ft_putchr(va_arg(args, int));
    else if(sign == 's')
        return ft_putstr(va_arg(args, char *));
    else if (sign == 'p')
        return ft_putptr(va_arg(args, unsigned long long));
    else if(sign == 'd' || sign == 'i')
        return ft_putnbr(va_arg(args, int));
    else if(sign == 'u')
        return ft_uitoa(va_arg(args, unsigned int));
    else if(sign == 'x' || sign == 'X')
        return ft_itoh(va_arg(args, unsigned int), sign);
    return 0;
}
