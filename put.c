/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 22:01:28 by iel-bouh          #+#    #+#             */
/*   Updated: 2019/07/09 13:50:07 by iel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_put(t_dir *files_dir, char *flags, char *path)
{
	t_dir *dirc;

	dirc = NULL;
	if (ft_used_f(flags, 'l') || ft_used_f(flags, 'o') || ft_used_f(flags, 'g'))
		ft_details(files_dir, path, flags);
	if (ft_used_f(flags, 'R'))
		ft_rec(files_dir, path, flags);
	if ((!ft_used_f(flags, 'l') && !ft_used_f(flags, 'o') &&
				!ft_used_f(flags, 'g')) && !ft_used_f(flags, 'R'))
		ft_list(files_dir, flags);
	return (0);
}

int		ft_put_arg(t_dir *files, char *flags, t_er_count er)
{
	t_dir		*dirc;
	t_spaces	sp;

	ft_set_space(1, &sp);
	dirc = NULL;
	ft_type_order(&files, &dirc);
	ft_put_files(files, flags, sp, &(er.count));
	if (er.count && dirc)
		ft_putchar('\n');
	ft_put_dir(dirc, flags, sp, er);
	ft_free(&dirc);
	return (0);
}

void	ft_put_files(t_dir *files, char *flg, t_spaces sp, int *count)
{
	while (files)
	{
		(*count)++;
		if (ft_used_f(flg, 'l') || ft_used_f(flg, 'o')
								|| ft_used_f(flg, 'g'))
		{
			ft_info(files, sp, ".", flg);
		}
		else
		{
			ft_list(files, flg);
			break ;
		}
		files = files->next;
	}
}

void	ft_put_dir(t_dir *dirc, char *flg, t_spaces sp, t_er_count er)
{
	while (dirc)
	{
		if ((dirc->next || er.count || er.error)
					&& (dirc->state).type[0] != 'l')
		{
			ft_putstr((dirc->state).name);
			ft_putendl(":");
			(er.count)++;
		}
		if ((dirc->state).type[0] == 'l' && (ft_used_f(flg, 'l') ||
					ft_used_f(flg, 'o') || ft_used_f(flg, 'g')))
		{
			if ((dirc->state).name[0] == '/')
				ft_info(dirc, sp, "", flg);
			else
				ft_info(dirc, sp, ".", flg);
		}
		else
			ft_put_extra(dirc, flg);
		if (dirc->next && (dirc->state).type[0] != 'l')
			ft_putchar('\n');
		dirc = dirc->next;
	}
}

void	ft_put_extra(t_dir *dirc, char *flg)
{
	t_dir *dir_extra;

	dir_extra = ft_extract_dir((dirc->state).name, flg);
	ft_merge_sort(&dir_extra, flg);
	ft_put(dir_extra, flg, (dirc->state).name);
	ft_free(&dir_extra);
}
