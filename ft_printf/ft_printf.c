/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:06:56 by mranaivo          #+#    #+#             */
/*   Updated: 2024/05/11 10:51:07 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(arg, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && ft_check_suiv(str[i + 1]))
		{
			i++;
			len += ft_check_print(str[i], arg);
		}
		else
			len += ft_printchar(str[i]);
		i++;
	}
	va_end(arg);
	return (len);
}
