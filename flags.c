/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 18:46:24 by iel-bouh          #+#    #+#             */
/*   Updated: 2019/07/09 13:49:28 by iel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_f_check(char *flags)
{
	int i;

	i = 0;
	while (flags[i] != '\0')
	{
		if (flags[i] == 'l' || flags[i] == 'a')
			i++;
		else if (flags[i] == 'R' || flags[i] == 'r')
			i++;
		else if (flags[i] == 't' || flags[i] == 'A')
			i++;
		else if (flags[i] == 'f' || flags[i] == 'g')
			i++;
		else if (flags[i] == 'o' || flags[i] == 'T')
			i++;
		else if (flags[i] == 'p' || flags[i] == 'S')
			i++;
		else
		{
			ft_f_error(flags[i]);
			return (-1);
		}
	}
	return (0);
}

int		ft_used_f(char *flags, char option)
{
	int i;

	i = 0;
	if (flags)
	{
		while (flags[i] != '\0')
		{
			if (flags[i] == option)
				return (1);
			i++;
		}
	}
	return (0);
}

void	ft_f_error(char flags)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(flags, 2);
	ft_putchar_fd('\n', 2);
	ft_putendl_fd("usage: ft_ls [-ARSTafgloprt] [file ...]", 2);
}
