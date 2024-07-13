/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 08:55:09 by mranaivo          #+#    #+#             */
/*   Updated: 2024/03/03 08:55:15 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbrlen(int n)
{
	size_t	cpt;

	cpt = 0;
	if (n == -2147483648)
	{
		cpt = 11;
		return (cpt);
	}
	if (n == 0)
	{
		cpt = 1;
		return (cpt);
	}
	while (n != 0)
	{
		if (n < 0)
		{
			n *= -1;
			cpt++;
		}
		n = n / 10;
		cpt++;
	}
	return (cpt);
}

static int	ft_neg(char *str, int *n)
{
	int	sign;

	sign = 1;
	if (*n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		*n = 147483648;
		sign = 2;
	}
	if (*n < 0)
	{
		str[0] = '-';
		*n *= -1;
		sign = -1;
	}
	return (sign);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	size_t	i;
	int		sign;

	len = ft_nbrlen(n);
	i = len;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	sign = ft_neg(str, &n);
	while (i != (int)0)
	{
		if (i == (int)1 && sign < 0)
			break ;
		if (i == (int)2 && sign == 2)
			break ;
		str[i - 1] = (char)((n % 10) + 48);
		n /= 10;
		i--;
	}
	str[len] = '\0';
	return (str);
}
