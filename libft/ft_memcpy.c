/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 18:26:19 by iel-bouh          #+#    #+#             */
/*   Updated: 2018/10/10 14:25:12 by iel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t					i;
	unsigned char			*s1;
	unsigned const char		*s2;

	s1 = dst;
	s2 = src;
	i = 0;
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (dst);
}
