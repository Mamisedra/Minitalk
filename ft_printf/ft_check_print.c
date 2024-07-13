/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:43:41 by mranaivo          #+#    #+#             */
/*   Updated: 2024/05/11 10:48:29 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_print(char str, va_list arg)
{
	int	low;
	int	up;
	int	result;

	low = 0;
	up = 0;
	if (str == 'c')
		result = (ft_printchar(va_arg(arg, int)));
	else if (str == 's')
		result = (ft_printstr(va_arg(arg, char *)));
	else if (str == 'p')
		result = (ft_put_point((unsigned long long)va_arg(arg, void *)));
	else if (str == 'd' || str == 'i')
		result = (ft_printnbr(va_arg(arg, int)));
	else if (str == 'u')
		result = (ft_putbase(va_arg(arg, unsigned int)));
	else if (str == 'x')
		result = (ft_puthexa_low(va_arg(arg, int), &low));
	else if (str == 'X')
		result = (ft_puthexa_up(va_arg(arg, int), &up));
	else if (str == '%')
		result = (ft_printchar('%'));
	return (result);
}
