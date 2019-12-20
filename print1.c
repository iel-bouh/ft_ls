/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 16:08:53 by iel-bouh          #+#    #+#             */
/*   Updated: 2019/07/09 13:50:03 by iel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_list(t_dir *head, char *flags)
{
	t_dir	*tmp;
	char	*tmp_1;

	tmp = head;
	while (tmp)
	{
		if (ft_strrchr((tmp->state).name, '/'))
		{
			tmp_1 = ft_strdup((tmp->state).name);
			free((tmp->state).name);
			(tmp->state).name = ft_strrchr(tmp_1, '/');
			free(tmp_1);
			(tmp->state).name = ft_strdup((tmp->state).name + 1);
		}
		ft_putstr((tmp->state).name);
		if (ft_used_f(flags, 'p') && (tmp->state).type[0] == 'd')
			ft_putchar('/');
		ft_putchar('\n');
		tmp = tmp->next;
	}
}

void	ft_min_maj(t_dir *files_dir, t_spaces sp)
{
	if ((files_dir->state).type[0] == 'b' || (files_dir->state).type[0] == 'c')
	{
		while (sp.maj_max > ft_ch_num((files_dir->state).maj))
		{
			ft_putchar(' ');
			(sp.maj_max)--;
		}
		ft_putnbr((files_dir->state).maj);
		ft_putstr(", ");
		while (sp.min_max > ft_ch_num((files_dir->state).min))
		{
			ft_putchar(' ');
			(sp.min_max)--;
		}
		ft_putnbr((files_dir->state).min);
		ft_putchar(' ');
	}
}

void	ft_future_date(t_dir *file, char *dat, char **dat1)
{
	char	*tmp;
	int		i;

	dat = ft_strsub((file->state).mtime_str, 4, 6);
	ft_putstr(dat);
	ft_putstr("  ");
	dat1 = ft_strsplit((file->state).mtime_str, ' ');
	tmp = ft_strdup(dat1[4]);
	i = -1;
	while (tmp[++i] != '\n')
		ft_putchar(tmp[i]);
	ft_memdel((void **)&tmp);
	i = -1;
	while (dat1[++i])
		ft_memdel((void **)&(dat1[i]));
	ft_memdel((void **)&dat1);
	ft_memdel((void **)&dat);
}
