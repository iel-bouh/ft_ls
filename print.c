/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bouh <iel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 16:13:45 by iel-bouh          #+#    #+#             */
/*   Updated: 2019/07/22 23:08:19 by iel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_info(t_dir *file, t_spaces sp, char *path, char *flag)
{
	char *tmp_1;

	while (sp.b_max > ft_ch_num((file->state).st_nlink))
	{
		sp.b_max--;
		ft_putchar(' ');
	}
	ft_putnbr((file->state).st_nlink);
	ft_print_uid_gid(file, flag, sp);
	ft_min_maj(file, sp);
	ft_print_size(file, sp);
	ft_print_date(file, flag);
	if (ft_strrchr((file->state).name, '/'))
	{
		tmp_1 = (file->state).name;
		(file->state).name = ft_strdup((ft_strrchr(tmp_1, '/') + 1));
		ft_memdel((void **)&tmp_1);
	}
	if (!ft_strcmp(path, "") && (file->state).type[0] == 'l')
		ft_putchar('/');
	ft_putstr((file->state).name);
	if (ft_used_f(flag, 'p') && (file->state).type[0] == 'd')
		ft_putchar('/');
	ft_print_link(file, path);
}

void	ft_print_uid_gid(t_dir *files_dir, char *flags, t_spaces space)
{
	if (!ft_used_f(flags, 'g'))
	{
		ft_putchar(' ');
		ft_putstr((files_dir->state).uid);
	}
	if (!ft_used_f(flags, 'o'))
	{
		while ((size_t)space.u_max > ft_strlen((files_dir->state).uid))
		{
			ft_putchar(' ');
			space.u_max--;
		}
		if (!ft_used_f(flags, 'g'))
			ft_putchar(' ');
		ft_putchar(' ');
		ft_putstr((files_dir->state).gid);
	}
	while ((size_t)space.g_max > ft_strlen((files_dir->state).gid))
	{
		ft_putchar(' ');
		space.g_max--;
	}
	ft_putstr("  ");
	if (ft_used_f(flags, 'o') && ft_used_f(flags, 'g'))
		ft_putchar(' ');
}

void	ft_print_size(t_dir *files_dir, t_spaces space)
{
	if ((files_dir->state).type[0] != 'b' && (files_dir->state).type[0] != 'c')
	{
		while (space.s_max > ft_ch_num((files_dir->state).st_size))
		{
			space.s_max--;
			ft_putchar(' ');
		}
		ft_putnbr((files_dir->state).st_size);
		ft_putstr(" ");
	}
}

void	ft_print_date(t_dir *file, char *flag)
{
	char	*dat;
	char	**dat1;

	dat = NULL;
	dat1 = NULL;
	if (!ft_used_f(flag, 'T'))
	{
		if ((time(NULL) - (file->state).mtime >= 15552000)
					|| (time(NULL) - (file->state).mtime < 0))
			ft_future_date(file, dat, dat1);
		else
		{
			dat = ft_strsub((file->state).mtime_str, 4, 12);
			ft_putstr(dat);
		}
	}
	else
	{
		dat = ft_strsub((file->state).mtime_str, 4, 20);
		ft_putstr(dat);
	}
	ft_putchar(' ');
	ft_memdel((void **)&dat);
}

void	ft_print_link(t_dir *files_dir, char *path)
{
	char buf[1024];
	char *tmp;

	if (((files_dir)->state).type[0] == 'l')
	{
		tmp = ft_strjoin(path, "/");
		path = ft_strjoin(tmp, (files_dir->state).name);
		ft_memset(buf, 0, sizeof(buf));
		readlink(path, buf, sizeof(buf));
		ft_putstr(" -> ");
		ft_putstr(buf);
		ft_memdel((void **)&tmp);
		ft_memdel((void **)&path);
	}
}
