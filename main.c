/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:51:19 by iel-bouh          #+#    #+#             */
/*   Updated: 2019/07/09 13:49:43 by iel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int arc, char **arv)
{
	t_dir		*files_dir;
	char		*flag;
	t_er_count	er;
	t_input		in;

	er.error = 0;
	er.count = 0;
	files_dir = NULL;
	flag = NULL;
	in.arc = arc;
	in.arv = arv;
	ft_run(files_dir, flag, er, in);
	return (0);
}

int		ft_run(t_dir *files_dir, char *flag, t_er_count er, t_input in)
{
	int			get;

	if ((get = ft_get(&files_dir, &flag, in, &(er.error))) == 2)
	{
		ft_free(&files_dir);
		ft_memdel((void **)&flag);
		return (0);
	}
	else if (get == 1)
	{
		ft_put_arg(files_dir, flag, er);
		ft_free(&files_dir);
		ft_memdel((void **)&flag);
		return (0);
	}
	else
	{
		ft_put(files_dir, flag, ".");
		ft_free(&files_dir);
		ft_memdel((void **)&flag);
	}
	if (files_dir != NULL)
		ft_free(&files_dir);
	return (0);
}

int		ft_get(t_dir **files_dir, char **flag, t_input in, int *error)
{
	ft_flags_files(files_dir, flag, in, error);
	if (*flag)
		if (ft_f_check(*flag) != 0)
			return (2);
	if (!(*(files_dir)) && *error == 0)
		*files_dir = ft_extract_dir(".", *flag);
	else if (!ft_used_f(*flag, 'f'))
	{
		ft_merge_sort(files_dir, *flag);
		return (1);
	}
	if (!ft_used_f(*flag, 'f'))
		ft_merge_sort(files_dir, *flag);
	if (!(*flag))
	{
		ft_list(*files_dir, *flag);
		ft_free(files_dir);
		return (2);
	}
	return (0);
}
