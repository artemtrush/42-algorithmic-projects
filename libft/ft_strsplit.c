/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 14:41:23 by atrush            #+#    #+#             */
/*   Updated: 2016/12/08 16:22:21 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**mas;
	int		size;
	int		i;
	int		k;

	if ((size = ft_countwd(s, c)) == -1)
		return (NULL);
	if (!(mas = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		k = 0;
		while (*s && *s == c)
			s++;
		while (s[k] && s[k] != c)
			k++;
		if (!(mas[i] = (char*)malloc(sizeof(char) * (k + 1))))
			return (NULL);
		ft_strncpy(mas[i], s, k);
		s = s + k;
		mas[i++][k] = '\0';
	}
	mas[size] = 0;
	return (mas);
}
