/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 18:32:33 by iel-bouh          #+#    #+#             */
/*   Updated: 2018/10/12 19:58:42 by iel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	int		i;
	char	*str;

	if (s1 && s2)
	{
		i = 0;
		len = ft_strlen(s1);
		str = (char *)malloc(sizeof(char) * (len + ft_strlen(s2) + 1));
		if (str == NULL)
			return (NULL);
		while (*s1 != '\0')
		{
			str[i] = *s1;
			s1++;
			i++;
		}
		while (*s2 != '\0')
		{
			str[i++] = *s2++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
