/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 14:01:52 by iel-bouh          #+#    #+#             */
/*   Updated: 2018/10/12 12:31:45 by iel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		res;
	size_t	i;

	res = 0;
	i = 0;
	while (dst[i] != '\0' && size > 0)
	{
		i++;
		size--;
	}
	res = ft_strlen(src) + i;
	if (size > 0)
	{
		while (*src != '\0' && size > 1)
		{
			dst[i] = *src;
			src++;
			i++;
			size--;
		}
		dst[i] = '\0';
	}
	return (res);
}
