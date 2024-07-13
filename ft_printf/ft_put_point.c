/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:19:47 by mranaivo          #+#    #+#             */
/*   Updated: 2024/05/11 10:47:46 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_convert(unsigned long long nb)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb < 16)
	{
		ft_printchar(base[nb]);
	}
	else if (nb >= 16)
	{
		ft_put_convert(nb / 16);
		ft_put_convert(nb % 16);
	}
}

int	ft_ret(unsigned long long nb)
{
	int	i;

	i = 0;
	while (nb != 0)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

int	ft_put_point(unsigned long long nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (ft_printstr("(nil)"));
	else
	{
		i += ft_printstr("0x");
		ft_put_convert(nb);
	}
	i += ft_ret(nb);
	return (i);
}
