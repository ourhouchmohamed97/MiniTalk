/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourhouc <mourhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:00:12 by mourhouc          #+#    #+#             */
/*   Updated: 2025/03/24 19:20:08 by mourhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

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