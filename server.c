/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreo <sreo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 13:56:48 by sreo              #+#    #+#             */
/*   Updated: 2024/07/14 19:03:50 by sreo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
void print_message(int sig)
{
    
}

int main(void){
    int id;
    
    id = getpid();
    ft_printf("Server PID %d\n", id);
    signal(SIGUSR1, print_message());
    signal(SIGUSR2, print_message());
    
    while(1)
        pause();
    return 0;
}
