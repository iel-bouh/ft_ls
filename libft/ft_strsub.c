/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 18:08:53 by iel-bouh          #+#    #+#             */
/*   Updated: 2018/10/13 14:20:31 by iel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int				count;
	char			*str;

	if (s)
	{
		count = 0;
		if (start > (unsigned int)ft_strlen(s))
			return (NULL);
		str = (char *)malloc((len + 1) * sizeof(char));
		if (str == NULL)
			return (NULL);
		while (s[start] != '\0' && len--)
			str[count++] = s[start++];
		str[count] = '\0';
		return (str);
	}
	return (NULL);
}
