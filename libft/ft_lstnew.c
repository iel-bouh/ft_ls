/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 12:10:47 by iel-bouh          #+#    #+#             */
/*   Updated: 2018/10/12 17:01:05 by iel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new != NULL)
	{
		if (content == NULL)
		{
			new->content = NULL;
			new->content_size = 0;
		}
		else
		{
			new->content = malloc(content_size);
			if (new->content == NULL)
				return (NULL);
			ft_memcpy(new->content, content, content_size);
			new->content_size = content_size;
		}
		new->next = NULL;
		return (new);
	}
	return (NULL);
}
