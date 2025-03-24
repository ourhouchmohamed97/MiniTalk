/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourhouc <mourhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:41:27 by mourhouc          #+#    #+#             */
/*   Updated: 2025/03/24 17:56:45 by mourhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	decrypt_message(int bit, int pid)
{
	static int	byte = 0;
	static int	byte_size = 1;

	byte <<= 1;
	byte += bit;
	if (byte_size == 8)
	{
		if (byte == '\0')
		{
			kill(pid, SIGUSR2);
			ft_printf("\n");
		}
		else
			ft_printf("%c", byte);
		byte = 0;
		byte_size = 1;
	}
	else
		byte_size++;
	kill(pid, SIGUSR1);
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	if (signum == SIGUSR1)
		decrypt_message(1, info->si_pid);
	else if (signum == SIGUSR2)
		decrypt_message(0, info->si_pid);
}

int	main(void)
{
	struct sigaction	action;

	action.sa_sigaction = signal_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO | SA_RESTART | SA_NODEFER;
	ft_printf("\033[32mServer started!\033[0m\n");
	ft_printf("--> Server PID: \033[1;93m%d\033[0m\n", getpid());
	ft_printf("\033[1;90mWaiting for messages...\033[0m\n"); 
	sigaction(SIGUSR1, &action, 0);
	sigaction(SIGUSR2, &action, 0);
	while (1)
		sleep(1);
	return (0);
}
