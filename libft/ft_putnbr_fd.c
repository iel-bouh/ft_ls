/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 11:50:12 by iel-bouh          #+#    #+#             */
/*   Updated: 2018/10/10 12:25:04 by iel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	i;

	i = 0;
	if (n < 0)
	{
		i = n * -1;
		ft_putchar_fd('-', fd);
	}
	else
		i = n;
	while (i > 9)
	{
		ft_putnbr_fd(i / 10, fd);
		i = i % 10;
	}
	ft_putchar_fd(i % 10 + '0', fd);
}
