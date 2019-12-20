/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 18:46:17 by iel-bouh          #+#    #+#             */
/*   Updated: 2018/10/12 16:30:21 by iel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	count;
	size_t	i;
	char	*str;

	count = 0;
	if (s)
	{
		i = ft_strlen(s);
		while ((*s == ' ' || *s == '\t' || *s == '\n') && *s != '\0')
		{
			s++;
			i--;
		}
		while ((s[i - 1] == ' ' || s[i - 1] == '\t' || s[i - 1] == '\n') && *s)
			i--;
		if ((str = (char *)malloc(i + 1)) != NULL)
		{
			while (count < i)
				str[count++] = *s++;
			str[count] = '\0';
			return (str);
		}
	}
	return (NULL);
}
