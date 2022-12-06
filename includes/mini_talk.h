/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:10:56 by anaraujo          #+#    #+#             */
/*   Updated: 2022/12/05 21:10:19 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK.H
# define MINI_TALK.H

# include "../libft/libft.h"

struct sigaction {
 union		sa_sigaction;  		/* signal handler */
 sigset_t   sa_mask;            /* signal mask to apply */
 int        sa_flags;           /* see signal options below */
};

#include <signal.h>

#endif