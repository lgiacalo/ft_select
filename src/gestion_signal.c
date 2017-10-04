/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 15:48:29 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/10/04 16:01:21 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
extern const char * const sys_siglist[];


void	gestion(int key)
{
	ft_fdprintf(1, "\n%ld a recu le signal %d (%s)\n",
			(long)getpid(), key, sys_siglist[key]);
}

void	gestion_signal(t_dlist *args)
{
	(void)args;
	int	i;

	i = 0;
	while (++i < NSIG)
	{
		if (signal(i, gestion) == SIG_ERR)
			ft_fdprintf(1, "\nSignal non capture (%d)\n", i);
	}
}
