/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:14:25 by iel-bouh          #+#    #+#             */
/*   Updated: 2018/10/10 21:57:36 by iel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*st1;
	unsigned char	*st2;

	st1 = (unsigned char *)s1;
	st2 = (unsigned char *)s2;
	while (n--)
	{
		if (*st1 == *st2)
		{
			st1++;
			st2++;
		}
		else
			return (*st1 - *st2);
	}
	return (0);
}
