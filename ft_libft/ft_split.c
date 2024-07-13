/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 09:00:24 by mranaivo          #+#    #+#             */
/*   Updated: 2024/03/03 09:00:27 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrstr(char const *str, char c)
{
	int	i;
	int	out;

	out = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == c)
			i++;
		if (str[i] != '\0')
			out++;
		while (str[i] != '\0' && str[i] != c)
			i++;
	}
	return (out);
}

static int	ft_error(char **split, int i, int end)
{
	int	j;

	j = 0;
	split[i] = malloc(sizeof(char) * (end));
	if (!split[i])
	{
		while (j < i)
		{
			free (split[j]);
			j++;
		}
		free (split);
		return (1);
	}
	return (0);
}

static int	ft_dup(char **split, char const *str, char c)
{
	int	i;
	int	len;

	i = 0;
	while (*str)
	{
		while (*str == c && *str)
			str++;
		len = 0;
		while (*str != c && *str)
		{
			str++;
			len++;
		}
		if (len)
		{
			if (ft_error(split, i, len + 1))
				return (1);
			ft_strlcpy(split[i], (str - len), len + 1);
		}
		i++;
	}
	return (0);
}

char	**ft_split(char const *str, char c)
{
	char	**split;
	int		nbr_str;

	if (!str)
		return (NULL);
	nbr_str = ft_nbrstr(str, c);
	split = (char **)malloc((nbr_str + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split[nbr_str] = NULL;
	if (ft_dup(split, str, c))
		return (NULL);
	return (split);
}
