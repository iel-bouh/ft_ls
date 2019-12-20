/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 19:12:54 by iel-bouh          #+#    #+#             */
/*   Updated: 2018/10/08 19:34:24 by iel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *str;

	str = (char *)malloc((size + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_bzero(str, (size + 1));
	return (str);
}
