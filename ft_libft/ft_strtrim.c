/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 09:05:18 by mranaivo          #+#    #+#             */
/*   Updated: 2024/03/03 09:05:21 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	l;
	char	*str;

	i = 0;
	while (ft_strchr(set, s1[i]) && s1[i] != '\0')
		i++;
	if (i >= ft_strlen(s1))
		return (ft_strdup(""));
	l = ft_strlen(s1);
	while (ft_strchr(set, s1[l - 1]) && (int)(l - 1) >= 0)
		l--;
	str = (char *)malloc(sizeof(char) * (l - i + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s1[i], l - i + 1);
	return (str);
}
