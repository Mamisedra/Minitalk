/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 09:03:16 by mranaivo          #+#    #+#             */
/*   Updated: 2024/03/03 09:03:23 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len_l;

	i = 0;
	j = 0;
	if (!*little)
		return ((char *)big);
	len_l = ft_strlen(little);
	while (big[i] != '\0')
	{
		j = 0;
		while (big[i + j] == little[j] && j < len_l && (i + j) < len)
			j++;
		if (j == len_l)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
