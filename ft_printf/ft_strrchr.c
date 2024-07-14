/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreo <sreo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:17:13 by sreo              #+#    #+#             */
/*   Updated: 2024/05/09 16:33:06 by sreo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int c)
{
	long long int	i;
	long			len;

	i = 0;
	len = 0;
	while (string[len])
		len++;
	while (i <= len)
	{
		if (string[len - i] == (char)c)
			return ((char *)&string[len - i]);
		i++;
	}
	return (NULL);
}
