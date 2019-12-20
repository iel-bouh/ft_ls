/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_outils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 21:21:46 by iel-bouh          #+#    #+#             */
/*   Updated: 2019/07/09 13:50:16 by iel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_type_order(t_dir **files_dir, t_dir **dirc)
{
	t_dir	*files;
	t_dir	*tmp;

	files = NULL;
	tmp = *files_dir;
	while (tmp)
	{
		if ((((tmp->state).type)[0] == 'd') || (((tmp->state).type[0] == 'l')
				&& (tmp->state).type[1] == 'd'))
			ft_add(&(*dirc), (tmp->state).name);
		else
			ft_add(&files, (tmp->state).name);
		tmp = tmp->next;
	}
	*files_dir = files;
}

int		ft_cond_t(char *flags, t_dir *a, t_dir *b)
{
	if (ft_used_f(flags, 'r'))
	{
		if ((a->state).mtime < (b->state).mtime ||
						((a->state).mtime == (b->state).mtime
							&& ft_strcmp((a->state).name, (b->state).name) > 0))
			return (1);
	}
	else if ((a->state).mtime > (b->state).mtime
				|| ((a->state).mtime == (b->state).mtime
					&& ft_strcmp((a->state).name, (b->state).name) < 0))
		return (1);
	return (0);
}

int		ft_cond_size(char *flags, t_dir *a, t_dir *b)
{
	if (ft_used_f(flags, 'r'))
	{
		if ((a->state).st_size < (b->state).st_size ||
						((a->state).st_size == (b->state).st_size
							&& ft_strcmp((a->state).name, (b->state).name) > 0))
			return (1);
	}
	else if ((a->state).st_size > (b->state).st_size
				|| ((a->state).st_size == (b->state).st_size
					&& ft_strcmp((a->state).name, (b->state).name) < 0))
		return (1);
	return (0);
}

int		ft_cond_re(char *flags, t_dir *a, t_dir *b)
{
	if (ft_used_f(flags, 'r') ?
				ft_strcmp((a->state).name, (b->state).name) > 0
						: ft_strcmp((a->state).name, (b->state).name) < 0)
		return (1);
	return (0);
}

int		ft_cond(t_dir *a, t_dir *b, char *flags)
{
	if (ft_used_f(flags, 'S'))
		return (ft_cond_size(flags, a, b));
	else if (ft_used_f(flags, 't'))
		return (ft_cond_t(flags, a, b));
	else
		return (ft_cond_re(flags, a, b));
}
