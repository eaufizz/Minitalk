/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreo <sreo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:37:00 by sreo              #+#    #+#             */
/*   Updated: 2024/07/20 17:24:01 by sreo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include <signal.h>

int	send_message(int pid, char *str)
{
	int				i;
	unsigned int	j;
	int				k;

	j = 0;
	while (str[j])
	{
		i = 8;
		while (--i >= 0)
		{
			if ((str[j] >> i) & 1)
				k = kill(pid, SIGUSR2);
			else
				k = kill(pid, SIGUSR1);
			usleep(400);
			if (k == -1)
				return (1);
		}
		j++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("error\n");
		return (1);
	}
	if (send_message(ft_atoi(argv[1]), argv[2]))
	{
		ft_printf("error\n");
		return (1);
	}
	ft_printf("success\n");
	return (0);
}
