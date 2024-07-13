/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:15:38 by mranaivo          #+#    #+#             */
/*   Updated: 2024/05/11 10:41:02 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_void(int nb)
{
	if (nb == -2147483648)
	{
		ft_printchar('-');
		ft_printchar('2');
		ft_printnbr(147483648);
	}
	else if (nb < 0)
	{
		ft_printchar('-');
		nb *= -1;
		ft_printnbr(nb);
	}
	else if (nb > 9)
	{
		ft_printnbr(nb / 10);
		ft_printnbr(nb % 10);
	}
	else
		ft_printchar(nb + 48);
}

int	ft_intlen(int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		len += 1;
	if (nb == -2147483648)
		return (11);
	if (nb < 0)
	{
		len++;
		nb *= -1;
	}
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

int	ft_printnbr(int nb)
{
	int	len;

	len = 0;
	len = ft_intlen(nb);
	ft_putnbr_void(nb);
	return (len);
}
