/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:19:22 by boss              #+#    #+#             */
/*   Updated: 2024/05/19 01:04:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int printptr(uintptr_t ptr)
{
    int i;
    int temp;
    char nbr[15];

    ft_bzero(nbr, 15);
    i = 0;
    while(ptr != 0)
    {
        temp = ptr % 16;
        if(temp < 10)
            nbr[i] = temp + 48;
        else
            nbr[i] = temp + 87;
        ptr /= 16;
        i++;
    }
    temp = i;
    while(i >= 0)
    {
        write(1, &nbr[i], 1);
        i--;
    }
    return temp;
}

int ft_putptr(unsigned long long ptr)
{
    write(1, "0x", 2);
    return printptr(ptr) + 2;
}
