/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bouh <iel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 12:41:42 by iel-bouh          #+#    #+#             */
/*   Updated: 2019/07/19 16:21:47 by iel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_free(t_dir **files_dir)
{
	t_dir	*tmp;

	tmp = NULL;
	while (*files_dir != NULL)
	{
		tmp = (*files_dir)->next;
		ft_memdel((void **)&(((*files_dir)->state).mtime_str));
		ft_memdel((void **)&(((*files_dir)->state).name));
		ft_memdel((void **)&(((*files_dir)->state).gid));
		ft_memdel((void **)&(((*files_dir)->state).uid));
		if (ft_strlen(((*files_dir)->state).type) == 2)
			ft_memdel((void **)&(((*files_dir)->state).type));
		ft_memdel((void **)&(*files_dir));
		*files_dir = tmp;
	}
}
