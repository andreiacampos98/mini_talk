/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:21:49 by anaraujo          #+#    #+#             */
/*   Updated: 2022/12/08 09:04:13 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_talk.h"

void	ft_send_message(pid_t pid_received, char *message)
{
	int				bit;
	unsigned char	c;

	while (*message)
	{
		c = *message;
		bit = 8;
		while (bit > 0)
		{
			if (c & 0b10000000)
				kill(pid_received, SIGUSR1);
			else
				kill(pid_received, SIGUSR2);
			usleep(100);
			bit--;
			c <<= 1;
		}
		message++;
	}
}

void	handler(int signum)
{
	if (signum == SIGUSR1)
		write(1, "Character has been sucessfully received!\n", 42);
}

int	main(int argc, char **argv)
{
	pid_t				pid_received;
	struct sigaction	s_sigaction;
	int					i;

	i = 0;
	if (argc != 3)
		handle_errors("Invalid number of arguments");
	while (argv[1][i])
		if (!ft_isdigit(argv[1][i++]))
			handle_errors("PID is not a number");
	if (argv[2] == 0)
		handle_errors("Invalid message");
	pid_received = ft_atoi(argv[1]);
	s_sigaction.sa_handler = &handler;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, NULL);
	sigaction(SIGUSR2, &s_sigaction, NULL);
	ft_send_message(pid_received, argv[2]);
	return (EXIT_SUCCESS);
}
