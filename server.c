/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreo <sreo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 13:56:48 by sreo              #+#    #+#             */
/*   Updated: 2024/07/16 20:42:27 by sreo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include <signal.h>

static void print_message(int sig)
{
    static int bit_count = 0;
    static unsigned char bit_letter = 0;

    if(sig == SIGUSR2)
        bit_letter |= 1;
    bit_count ++;
    if(bit_count == 8)
    {
        write(1, &bit_letter, 1);
        bit_count = 0;
        bit_letter = 0;
    }
    else
        bit_letter <<= 1;
}

int main(void){
    int id;
    
    id = getpid();
    ft_printf("Server PID %d\n", id);
    signal(SIGUSR1, print_message);
    signal(SIGUSR2, print_message);
    while(1)
        pause();
    return 0;
}
