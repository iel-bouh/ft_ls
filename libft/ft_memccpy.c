/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 20:04:31 by iel-bouh          #+#    #+#             */
/*   Updated: 2018/10/10 21:35:04 by iel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char	*st1;
	unsigned char	*st2;

	st1 = (unsigned char *)s1;
	st2 = (unsigned char *)s2;
	while (n > 0)
	{
		*st1 = *st2;
		st1++;
		if (*st2 == (unsigned char)c)
			return ((void *)(st1));
		st2++;
		n--;
	}
	return (NULL);
}
