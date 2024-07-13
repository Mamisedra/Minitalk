/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_low.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:30:55 by mranaivo          #+#    #+#             */
/*   Updated: 2024/05/11 10:46:55 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa_low(unsigned int nb, int *i)
{
	char			*b;
	unsigned long	nbr;

	nbr = (unsigned long int)nb;
	b = "0123456789abcdef";
	if (nbr < 16)
	{
		*i += ft_printchar(b[nbr]);
		return (*i);
	}
	else
	{
		ft_puthexa_low(nbr / 16, i);
		ft_puthexa_low(nbr % 16, i);
	}
	return (*i);
}

int	ft_puthexa_up(unsigned int nb, int *i)
{
	char			*b;
	unsigned long	nbr;

	nbr = (unsigned long int)nb;
	b = "0123456789ABCDEF";
	if (nbr < 16)
	{
		*i += ft_printchar(b[nbr]);
		return (*i);
	}
	else
	{
		ft_puthexa_up(nbr / 16, i);
		ft_puthexa_up(nbr % 16, i);
	}
	return (*i);
}
