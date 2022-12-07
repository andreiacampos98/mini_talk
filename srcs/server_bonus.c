/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:21:46 by anaraujo          #+#    #+#             */
/*   Updated: 2022/12/07 23:18:50 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_talk.h"

void	handler(int sig, siginfo_t *info, void *ucontext)
{
	static int				bit = -1;
	static unsigned char	c = 0;

	(void)ucontext;
	if (bit < 0)
		bit = 7;
	if (sig == SIGUSR1)
		c = c | (1 << bit);
	bit--;
	if (bit < 0 && c)
	{
		ft_putchar(c);
		if (kill(info->si_pid, SIGUSR1) == -1)
			handle_errors("couldn't send a signal back to the client");
		c = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	s_sigaction;

	pid = getpid();
	ft_printf("The server PID: %d\n", pid);
	s_sigaction.sa_sigaction = handler;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, NULL);
	sigaction(SIGUSR2, &s_sigaction, NULL);
	while (1)
		pause();
	return (0);
}
