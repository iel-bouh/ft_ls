/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colones.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 15:07:12 by iel-bouh          #+#    #+#             */
/*   Updated: 2019/07/09 13:48:59 by iel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_info(t_dir *files_dir, t_spaces sp, char *path, char *fg)
{
	char	xattr[1024];
	acl_t	acl;

	ft_putchar((files_dir->state).type[0]);
	ft_putstr((files_dir->state).permissions);
	sp.b_max = ft_ch_num(sp.b_max);
	if (listxattr((files_dir->state).name, xattr, 1024, XATTR_NOFOLLOW) > 0)
	{
		ft_putstr("@");
		ft_putstr(" ");
	}
	else if ((acl = acl_get_link_np((files_dir->state).name,
												ACL_TYPE_EXTENDED)))
	{
		ft_putstr("+");
		ft_putstr(" ");
		acl_free(acl);
	}
	else
		ft_putstr("  ");
	ft_print_info(files_dir, sp, path, fg);
	ft_putchar('\n');
}

int		ft_details(t_dir *head, char *path, char *flags)
{
	int			total;
	t_dir		*tmp;
	t_spaces	space;

	total = 0;
	if (head)
	{
		ft_set_space(0, &space);
		tmp = head;
		ft_cal_sp(head, &space, &total);
		ft_putstr("total ");
		ft_putnbr(total);
		ft_putchar('\n');
		tmp = head;
		while (tmp)
		{
			ft_info(tmp, space, path, flags);
			tmp = tmp->next;
		}
	}
	return (0);
}

void	ft_cal_sp(t_dir *head, t_spaces *space, int *total)
{
	while (head)
	{
		if ((unsigned long)(*space).b_max < (head->state).st_nlink)
			(*space).b_max = (head->state).st_nlink;
		if ((size_t)(*space).u_max < ft_strlen((head->state).uid))
			(*space).u_max = ft_strlen((head->state).uid);
		if ((size_t)(*space).g_max < ft_strlen((head->state).gid))
			(*space).g_max = ft_strlen((head->state).gid);
		if ((*space).s_max < (head->state).st_size)
			(*space).s_max = (head->state).st_size;
		if ((*space).min_max < (head->state).min)
			(*space).min_max = (head->state).min;
		if ((*space).maj_max < (head->state).maj)
			(*space).maj_max = (head->state).maj;
		*total += (head->state).st_blocks;
		head = head->next;
	}
	(*space).s_max = ft_ch_num((*space).s_max);
	(*space).min_max = ft_ch_num((*space).min_max);
	(*space).maj_max = ft_ch_num((*space).maj_max);
}

int		ft_ch_num(int i)
{
	int count;

	count = 0;
	while ((i / 10) > 0)
	{
		count++;
		i /= 10;
	}
	return (count + 1);
}

void	ft_set_space(int i, t_spaces *space)
{
	(*space).b_max = i;
	(*space).u_max = i;
	(*space).g_max = i;
	(*space).s_max = i;
	(*space).min_max = i;
	(*space).maj_max = i;
}
