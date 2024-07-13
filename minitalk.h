/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:52:36 by mranaivo          #+#    #+#             */
/*   Updated: 2024/07/13 14:09:35 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "./ft_printf/ft_printf.h"
# include "./ft_libft/libft.h"
# include <signal.h>
# include <stdlib.h>

char	*ft_dup_min(char c);
char	*char_join_str(char *last_message, char c);
void	signal_handler(int signum, siginfo_t *info, void *context);
void	ft_send_end_of_file(pid_t pid);
void	char_to_bit(char *message, pid_t pid);

#endif