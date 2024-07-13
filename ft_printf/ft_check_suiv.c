/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_suiv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:44:40 by mranaivo          #+#    #+#             */
/*   Updated: 2024/03/16 16:07:57 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_suiv(char str)
{
	char	*s;
	int		j;

	s = "cspdiuxX%";
	j = 0;
	while (s[j] != '\0')
	{
		if (str == s[j])
			return (1);
		else
			j++;
	}
	return (0);
}
