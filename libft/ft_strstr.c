/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 16:15:25 by iel-bouh          #+#    #+#             */
/*   Updated: 2018/10/08 14:41:15 by iel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char *needle_cpy;
	const char *index;

	if (*needle == '\0')
		return ((char *)haystack);
	needle_cpy = needle;
	while (*haystack != *needle && *haystack != '\0')
		haystack++;
	index = haystack;
	while (*haystack == *needle && *haystack != '\0' && *needle != '\0')
	{
		haystack++;
		needle++;
	}
	if (*needle == '\0')
		return ((char *)index);
	if (*haystack == '\0')
		return (NULL);
	index++;
	return (ft_strstr(index, needle_cpy));
}
