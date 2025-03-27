/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourhouc <mourhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:41:21 by mourhouc          #+#    #+#             */
/*   Updated: 2025/03/27 13:12:41 by mourhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int		g_server_ready;

void	encrypt_message(unsigned char letter, int pid)
{
	int	i;
	int	bit;

	i = 0;
	while (i < 8)
	{
		if (kill(pid, 0) < 0)
		{
			ft_printf("\033[31mInvalid or null PID!\033[0m");
			exit(EXIT_FAILURE);
		}
		g_server_ready = 0;
		bit = letter & 128;
		letter <<= 1;
		i++;
		if (bit == 128)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_server_ready != 1)
			usleep(10);
	}
}

void	send_message(char *msg, int pid)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		encrypt_message(msg[i], pid);
		i++;
	}
	encrypt_message('\0', pid);
}

void	check_status(int signum)
{
	if (signum == SIGUSR2)
		exit(EXIT_SUCCESS);
	else if (signum == SIGUSR1)
		g_server_ready = 1;
}

int	main(int argc, char **argv)
{
	int	server_id;

	if (argc != 3)
	{
		ft_printf("\033[31mError: Invalid arguments!\033[0m");
		ft_printf("	Usage: ./client PID MESSAGE");
		return (1);
	}
	signal(SIGUSR1, &check_status);
	signal(SIGUSR2, &check_status);
	server_id = ft_atoi(argv[1]);
	if (server_id <= 0)
	{
		ft_printf("\033[31mError: Invalid PID!\033[0m");
		exit(EXIT_FAILURE);
	}
	send_message(argv[2], server_id);
	while (1)
		sleep(1);
	return (0);
}
