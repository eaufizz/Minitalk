/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:42:25 by sreo              #+#    #+#             */
/*   Updated: 2024/05/18 14:22:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include "libft/libft.h"

int ft_printf(const char *format, ...);
int format_processor(char sign, va_list args);
int ft_putchr(int c);
int ft_putstr(char *str);
int ft_putptr(unsigned long long ptr);
int ft_putnbr(int nbr);
int ft_uitoa(unsigned int n);
int ft_itoh(unsigned int nbr, char sign);

#endif