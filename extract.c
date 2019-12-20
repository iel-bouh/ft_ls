/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bouh <iel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:14:22 by iel-bouh          #+#    #+#             */
/*   Updated: 2019/07/22 23:04:37 by iel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_flags_files(t_dir **file, char **flag, t_input in, int *er)
{
	int	memaloc;
	int	i;

	memaloc = 0;
	i = 1;
	if (in.arc > 1)
	{
		ft_add_flag(flag, in.arv, &i, memaloc);
		ft_add_file(file, in.arv, i, er);
	}
	return (0);
}

void	ft_add_flag(char **flags, char **arv, int *i, int memaloc)
{
	while (arv[*i] != '\0')
	{
		if (arv[*i][0] != '-' || !(ft_strcmp(arv[*i], "--")) ||
										!(ft_strcmp(arv[*i], "-")))
		{
			if (!ft_strcmp(arv[*i], "--"))
				(*i)++;
			break ;
		}
		else
		{
			if (memaloc == 0)
			{
				if (!(*flags = ft_strdup(&(arv[*i][1]))))
					return ;
				memaloc++;
			}
			else
			{
				*flags = ft_strjoin(*flags, &(arv[*i][1]));
			}
		}
		(*i)++;
	}
}

void	ft_add_file(t_dir **file, char **arv, int i, int *er)
{
	while (arv[i] != '\0')
	{
		if (ft_add(file, arv[i]) == -1)
		{
			ft_error(arv[i]);
			(*er)++;
		}
		i++;
	}
}

void	ft_read_dir(char *name, char *flags, DIR *pdir, t_dir **file)
{
	struct dirent	*st_dir;
	char			*name_tmp;

	name_tmp = NULL;
	while ((st_dir = readdir(pdir)))
	{
		if ((st_dir->d_name[0] != '.') || (ft_used_f(flags, 'A')
				|| (ft_used_f(flags, 'a')) || (ft_used_f(flags, 'f'))))
		{
			if ((ft_strcmp(st_dir->d_name, ".") &&
					ft_strcmp(st_dir->d_name, ".."))
						|| (ft_used_f(flags, 'a') || (ft_used_f(flags, 'f'))))
			{
				name_tmp = name;
				name = ft_join_path(name, st_dir->d_name);
				ft_add(file, name);
				ft_memdel((void **)&name);
				name = name_tmp;
			}
		}
	}
}

t_dir	*ft_extract_dir(char *name, char *flags)
{
	t_dir	*files_dir;
	DIR		*pdir;

	files_dir = NULL;
	pdir = opendir(name);
	if (!pdir)
	{
		ft_error((char *)name);
		return (NULL);
	}
	ft_read_dir(name, flags, pdir, &files_dir);
	closedir(pdir);
	return (files_dir);
}
