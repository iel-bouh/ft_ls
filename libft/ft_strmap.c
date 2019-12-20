/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 20:14:42 by iel-bouh          #+#    #+#             */
/*   Updated: 2018/10/12 19:42:49 by iel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*res;

	if (s && f)
	{
		i = 0;
		res = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (res == NULL)
			return (NULL);
		while (*s != '\0')
		{
			res[i] = f(*s);
			s++;
			i++;
		}
		res[i] = '\0';
		return (res);
	}
	return (NULL);
}
