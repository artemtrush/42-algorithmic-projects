/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:27:03 by atrush            #+#    #+#             */
/*   Updated: 2016/12/07 16:43:15 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;

	new = NULL;
	if (!lst || !f)
		return (NULL);
	if (lst->next)
		new = ft_lstmap(lst->next, f);
	tmp = f(lst);
	if (!tmp)
	{
		if (new)
			ft_lstfree(&new);
		return (NULL);
	}
	tmp->next = new;
	return (tmp);
}
