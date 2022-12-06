/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:21:46 by anaraujo          #+#    #+#             */
/*   Updated: 2022/12/06 21:02:39 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_talk.h"

void    handler(int sig, siginfo_t *info, void *ucontext)
{
	static int		bit;
	static unsigned char   c;

	bit = -1;
	c = 0;
	if (c < 0)
		bit = 7;
	if (sig == SIGUSR1)
		c = c | (1 << bit);
	bit--;
	if (bit < 0 && c)
	{
		ft_putchar(c);
		c = 0;
	}
}

int main()
{
    pid_t				pid;
    struct sigaction	s_sigaction;

    pid = getpid();
    ft_printf("The server PID: %i", pid);
    s_sigaction.sa_sigaction = handler;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
    while (1)
        pause();
    return (0);
    
}