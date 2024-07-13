/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:33:51 by mranaivo          #+#    #+#             */
/*   Updated: 2024/07/13 14:11:41 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../ft_libft/libft.h"
#include <signal.h>

char	*ft_dup(char c)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

char	*char_join_str(char *last_message, char c)
{
	int		len;
	int		i;
	char	*new_message;

	len = ft_strlen(last_message);
	new_message = (char *)malloc(sizeof(char) * (len + 2));
	if (!new_message)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_message[i] = last_message[i];
		i++;
	}
	new_message[i] = c;
	new_message[++i] = '\0';
	free(last_message);
	return (new_message);
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static char	*last_message = NULL;
	static int	count = 0;
	static int	result = 0;

	(void)context;
	(void)info;
	if (last_message == NULL)
		last_message = ft_dup('\0');
	if (signum == SIGUSR2)
		result |= 0;
	else if (signum == SIGUSR1)
		result |= (1 << 7 - count);
	count++;
	if (count == 8)
	{
		last_message = char_join_str(last_message, result);
		if (result == '\0')
		{
			ft_printf("\033[0;37m%s\033[0m\n", last_message);
			free(last_message);
			last_message = NULL;
		}
		count = 0;
		result = 0;
	}
}

int	main(void)
{
	struct sigaction	action;

	action.sa_sigaction = signal_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	ft_printf("\033[1;35mSERVER - PID : %d\033[0m\n", getpid());
	ft_printf("\033[5;34mMESSAGE : \033[0m\n");
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}
