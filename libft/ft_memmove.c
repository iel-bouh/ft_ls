/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 11:22:20 by iel-bouh          #+#    #+#             */
/*   Updated: 2018/10/12 21:24:35 by iel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		move[len];
	char		*s1;
	const char	*s2;

	i = 0;
	s1 = dst;
	s2 = src;
	if (len > 65535)
		return (0);
	while (i < len)
	{
		move[i] = s2[i];
		i++;
	}
	move[len] = '\0';
	i = 0;
	while (i < len)
	{
		s1[i] = move[i];
		i++;
	}
	return (dst);
}
