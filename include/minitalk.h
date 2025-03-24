/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourhouc <mourhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 14:39:58 by mourhouc          #+#    #+#             */
/*   Updated: 2025/03/24 19:19:50 by mourhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft_utils/printf/ft_printf.h"
# include "../libft_utils/libft/libft.h"
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

// ------------ client functions ------------
void	encrypt_message(unsigned char letter, int pid);
void	send_message(char *msg, int pid);
void	check_status(int signum);

// ------------ server functions ------------
void	decrypt_message(int bit, int pid);
void	signal_handler(int signum, siginfo_t *info, void *context);

#endif