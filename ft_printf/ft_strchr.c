/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreo <sreo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:34:19 by sreo              #+#    #+#             */
/*   Updated: 2024/05/09 16:35:49 by sreo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int c)
{
	int		i;
	char	cc;

	i = 0;
	cc = c;
	while (string[i])
	{
		if (string[i] == cc)
			return ((char *)&string[i]);
		i++;
	}
	if (string[i] == cc)
		return ((char *)&string[i]);
	return (NULL);
}
