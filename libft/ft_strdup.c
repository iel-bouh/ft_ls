/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 15:31:31 by iel-bouh          #+#    #+#             */
/*   Updated: 2018/10/12 13:01:24 by iel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int		i;
	char	*s1;
	int		len;

	i = 0;
	len = 0;
	while (s[len] != '\0')
		len++;
	s1 = (char *)malloc(sizeof(char) * (len + 1));
	if (s1 == NULL)
		return (NULL);
	while (i < len)
	{
		s1[i] = *s;
		s++;
		i++;
	}
	s1[len] = '\0';
	return (s1);
}
