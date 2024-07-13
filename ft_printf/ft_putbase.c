/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:21:01 by mranaivo          #+#    #+#             */
/*   Updated: 2024/05/11 10:47:14 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_intlen(unsigned int nb)
{
	unsigned int	len;

	len = 0;
	if (nb == 0)
		len = 1;
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static void	ft_calcl(unsigned int nb)
{
	if (nb == 0)
		ft_printchar('0');
	else if (nb < 10)
		ft_printchar(48 + nb);
	else
	{
		ft_calcl(nb / 10);
		ft_calcl(nb % 10);
	}
}

int	ft_putbase(unsigned int nb)
{
	unsigned int	k;

	k = ft_intlen(nb);
	ft_calcl(nb);
	return (k);
}
