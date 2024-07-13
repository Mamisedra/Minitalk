/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 09:00:43 by mranaivo          #+#    #+#             */
/*   Updated: 2024/03/03 09:00:44 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len_str;
	size_t	i;
	char	*str;

	len_str = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * len_str + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len_str)
	{
		str[i] = (char)s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
