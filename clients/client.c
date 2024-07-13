/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:33:56 by mranaivo          #+#    #+#             */
/*   Updated: 2024/07/13 14:09:44 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../ft_libft/libft.h"
#include <stdlib.h>
#include <signal.h>

void	ft_send_end_of_file(pid_t pid)
{
	int	bit;

	bit = 8;
	while (bit--)
	{
		kill(pid, SIGUSR2);
		usleep(400);
	}
}

void	send_signal(int pid, int signal, int time)
{
	if (signal == 1)
	{
		usleep(time);
		if (kill(pid, SIGUSR1) < 0)
		{
			ft_printf("\033[1;31mERROR PID, Failed to send SIGUSR1\033[0m\n");
			exit(0);
			return ;
		}
	}
	else if (signal == 0)
	{
		usleep(time);
		if (kill(pid, SIGUSR2) < 0)
		{
			ft_printf("\033[1;31m ERROR PID, Failed to send SIGUSR2\033[0m\n");
			exit(0);
			return ;
		}
	}
}

void	char_to_bit(char *message, pid_t pid)
{
	int	i;
	int	bit;

	i = 0;
	while (message[i])
	{
		bit = 8;
		while (bit > 0)
		{
			bit--;
			if ((message[i] >> bit) & 1)
				send_signal(pid, 1, 0);
			else
				send_signal(pid, 0, 0);
			usleep(400);
		}
		i++;
		usleep(400);
	}
	ft_send_end_of_file(pid);
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_printf("\033[1;31mERROR, Usage  :\
		  %s <PID> <Message>\033[0m\n", argv[0]);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("\033[1;31mERROR: Invalid PID\n\033[0m");
		return (1);
	}
	if (!ft_strlen(argv[2]))
	{
		ft_printf("\033[1;31mERROR: Empty message\033[0m\n");
		return (1);
	}
	char_to_bit(argv[2], pid);
	return (0);
}
