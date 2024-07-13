/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:23:10 by mranaivo          #+#    #+#             */
/*   Updated: 2024/05/11 12:03:12 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *newv)
{
	t_list	*tmp;

	if (lst)
	{
		if (*lst == NULL)
			*lst = newv;
		else
		{
			tmp = ft_lstlast(*(lst));
			tmp->next = newv;
		}
	}
}
