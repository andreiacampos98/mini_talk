/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:21:49 by anaraujo          #+#    #+#             */
/*   Updated: 2022/12/05 21:12:18 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/mini_talk.h"

void	handle_errors(char *error_msg)
{
	write(STDERR_FILENO, "Error: ", 7);
	write(STDERR_FILENO, error_msg, ft_strlen(error_msg));
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}

void	ft_send_message(pid_t pid_received, char *message)
{
	int		bit;
	int		i;

	i = 0;
	while (message[i])
	{
		bit = 8;
		while (bit > 0)
		{
			if (message[i] & 0b10000000)
				kill(pid_received, SIGUSR1);
			else
				kill(pid_received, SIGUSR2);
			usleep(15);
			bit--;
			message[i] <<= 1;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid_received;
	int		i;

	i = 0;
	if (argc != 3)
		handle_errors("Invalid number of arguments");
	while (argv[1][i])
		if (!ft_is_digit(argv[1][i++]))
			handle_errors("PID is not a number");
	if (argv[2] = 0)
		handle_error("Invalid message");
	pid_received = ft_atoi(argv[1]);
	ft_send_message(pid_received, argv[2]);
	
	return (0);
	
}