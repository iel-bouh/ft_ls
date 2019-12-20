/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 20:03:36 by iel-bouh          #+#    #+#             */
/*   Updated: 2018/10/10 11:43:33 by iel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr(int n)
{
	unsigned int	i;

	i = 0;
	if (n < 0)
	{
		i = n * -1;
		ft_putchar('-');
	}
	else
		i = n;
	while (i > 9)
	{
		ft_putnbr(i / 10);
		i = i % 10;
	}
	ft_putchar(i % 10 + '0');
}
