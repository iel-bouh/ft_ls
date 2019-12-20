/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bouh <iel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 01:01:03 by iel-bouh          #+#    #+#             */
/*   Updated: 2019/07/22 23:11:50 by iel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_rec(t_dir *file_store, char *path, char *flags)
{
	if (file_store)
	{
		if (!ft_used_f(flags, 'l'))
			ft_list(file_store, flags);
		if (!strcmp(path, "/"))
			ft_rec_check(file_store, "", flags);
		else
			ft_rec_check(file_store, path, flags);
	}
}

void	ft_rec_check(t_dir *file_store, char *path, char *flags)
{
	char	*path_tmp;
	t_dir	*files_dir;

	while (file_store)
	{
		if (ft_strcmp((file_store->state).name, ".")
			&& ft_strcmp((file_store->state).name, ".."))
		{
			path_tmp = path;
			path = ft_join_path(path_tmp, (file_store)->state.name);
			if ((((file_store)->state).type[0]) == 'd')
			{
				ft_putchar('\n');
				ft_putstr(path);
				ft_putendl(":");
				files_dir = ft_extract_dir(path, flags);
				ft_merge_sort(&files_dir, flags);
				ft_put(files_dir, flags, path);
				ft_free(&files_dir);
			}
			ft_memdel((void **)&path);
			path = path_tmp;
		}
		file_store = file_store->next;
	}
}

char	*ft_join_path(char *path, char *name)
{
	char *path_1;

	path_1 = ft_strjoin(path, "/");
	path = ft_strjoin(path_1, name);
	ft_memdel((void **)&path_1);
	return (path);
}
