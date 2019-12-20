/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 14:03:59 by iel-bouh          #+#    #+#             */
/*   Updated: 2018/10/12 19:44:11 by iel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (s && f)
	{
		i = 0;
		str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (str == NULL)
			return (NULL);
		while (s[i] != '\0')
		{
			str[i] = (char)f(i, s[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
