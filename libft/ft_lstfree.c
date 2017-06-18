/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:34:04 by atrush            #+#    #+#             */
/*   Updated: 2016/12/07 16:42:53 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstfree(t_list **alst)
{
	if (!*alst)
		return ;
	if ((*alst)->next)
		ft_lstfree(&((*alst)->next));
	free(*alst);
	*alst = NULL;
}
