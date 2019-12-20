/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bouh <iel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 16:58:02 by iel-bouh          #+#    #+#             */
/*   Updated: 2019/07/23 15:06:41 by iel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_split(t_dir *sc, t_dir **fr, t_dir **ba)
{
	t_dir	*fast;
	t_dir	*slow;

	slow = sc;
	fast = sc->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*fr = sc;
	*ba = slow->next;
	slow->next = NULL;
}

t_dir		*ft_sorted(t_dir *a, t_dir *b, char *flags)
{
	t_dir	*result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (ft_cond(a, b, flags))
	{
		result = a;
		result->next = ft_sorted(a->next, b, flags);
	}
	else
	{
		result = b;
		result->next = ft_sorted(a, b->next, flags);
	}
	return (result);
}

void		ft_merge_sort(t_dir **head, char *flags)
{
	t_dir	*tmp;
	t_dir	*a;
	t_dir	*b;

	tmp = *head;
	if ((tmp == NULL) || (tmp->next == NULL))
		return ;
	ft_split(tmp, &a, &b);
	ft_merge_sort(&a, flags);
	ft_merge_sort(&b, flags);
	*head = ft_sorted(a, b, flags);
}
