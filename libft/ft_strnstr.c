/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 18:20:22 by iel-bouh          #+#    #+#             */
/*   Updated: 2018/10/13 13:47:43 by iel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strnstr(const char *stack, const char *needle, size_t len)
{
	size_t i;

	i = ft_strlen(needle);
	if (*needle == '\0')
		return ((char *)stack);
	while (*stack != '\0' && len > 0)
	{
		if (!ft_strncmp(stack, needle, i) && i <= len)
			return ((char *)stack);
		if (i == len)
			return (NULL);
		stack++;
		len--;
	}
	return (NULL);
}
