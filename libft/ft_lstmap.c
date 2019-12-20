/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 17:31:27 by iel-bouh          #+#    #+#             */
/*   Updated: 2018/10/11 19:22:19 by iel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_lst;
	t_list *tmp;

	tmp = f(lst);
	new_lst = tmp;
	while (lst->next)
	{
		lst = lst->next;
		tmp->next = f(lst);
		tmp = tmp->next;
	}
	return (new_lst);
}
