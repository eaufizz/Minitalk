/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:07:58 by marvin            #+#    #+#             */
/*   Updated: 2024/05/18 14:07:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int    digit_count(unsigned int n)
{
    int    count;

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

int    ft_uitoa(unsigned int n)
{
    int        count;
    char    result[11];

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
