/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 16:32:28 by iel-bouh          #+#    #+#             */
/*   Updated: 2018/10/12 19:34:47 by iel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_digit_nb(int n)
{
	int			len;
	long int	nb;

	nb = n;
	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		nb *= -1;
	while (nb > 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char		*str;
	long int	nb;
	int			len;

	nb = n;
	len = ft_digit_nb(n);
	if (nb < 0)
		len++;
	if ((str = (char *)malloc(sizeof(char) * len + 1)) != NULL)
	{
		if (nb == 0)
			str[0] = '0';
		if (nb < 0)
			str[0] = '-';
		nb = (nb < 0) ? (-1 * nb) : nb;
		str[len--] = '\0';
		while (nb > 0)
		{
			str[len--] = (nb % 10 + '0');
			nb /= 10;
		}
		return (str);
	}
	return (NULL);
}
