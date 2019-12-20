/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 17:31:08 by iel-bouh          #+#    #+#             */
/*   Updated: 2019/07/09 13:49:04 by iel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_error(char *file)
{
	if (*file)
	{
		ft_putstr_fd("ls: ", 2);
		ft_check_error(&file);
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": ", 2);
		perror("");
	}
	else
	{
		ft_putstr_fd("ls: ", 2);
		ft_check_error(&file);
		ft_putstr_fd("fts_open", 2);
		ft_putstr_fd(": ", 2);
		perror("");
	}
}

void	ft_check_error(char **file)
{
	if (!ft_strcmp(strerror(errno), "Permission denied"))
	{
		if (ft_strrchr(*file, '/'))
		{
			*file = ft_strrchr(*file, '/');
			(*file)++;
		}
	}
}
