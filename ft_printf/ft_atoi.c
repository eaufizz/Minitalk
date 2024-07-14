/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreo <sreo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:56:38 by sreo              #+#    #+#             */
/*   Updated: 2024/05/09 16:49:05 by sreo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	space_minus_zerocheck(const char *str, int *i)
{
	int	minus;

	minus = 2;
	while (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n'
		|| str[*i] == '\v' || str[*i] == '\f' || str[*i] == '\r')
		*i += 1;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			minus++;
		*i += 1;
	}
	while (str[*i] == '0')
		*i += 1;
	if (minus % 2 == 1)
		return (-1);
	else
		return (1);
}

static unsigned long long	nbrread(const char *str, int i, int *minus)
{
	int				j;
	unsigned long	result;

	j = 0;
	result = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		if ((result > (unsigned long)LONG_MAX / 10 || result
				* 10 > (unsigned long)LONG_MAX - (str[i] - '0')) && *minus == 1)
			return (LONG_MAX);
		if ((result > (unsigned long)LONG_MAX + 1 / 10 || result
				* 10 > (unsigned long)LONG_MAX + 1 - (str[i] - '0'))
			&& *minus == -1)
			return (LONG_MIN);
		result = result * 10 + (str[i] - '0');
		i += 1;
		j++;
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					minus;
	unsigned long long	result;

	i = 0;
	while (str[i] == ' ')
		i++;
	minus = space_minus_zerocheck(str, &i);
	result = nbrread(str, i, &minus) * minus;
	return (result);
}
