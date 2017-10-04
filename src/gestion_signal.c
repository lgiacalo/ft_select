/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 15:48:29 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/10/05 00:14:13 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

extern const char * const sys_siglist[];

void	gestion_susp(int key)
{
	(void)key;
	term_original();
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, "\032");
}

void	gestion_cont(int key)
{
	(void)key;
	signal(SIGTSTP, gestion_susp);
	mode_non_canonique();
	affichage_args(env()->args);
}

void	gestion_int(int key)
{
	(void)key;
	term_original();
	gestion_end(env()->args, 27);
	ft_dlstfree(&(env()->args), del);
	ft_fdprintf(1, "\n====== FIN 2 ======\n"); //
	exit(EXIT_SUCCESS);	
}

void	gestion(int key)
{
	ft_fdprintf(1, "\n%ld a recu le signal %d (%s)\n",
			(long)getpid(), key, sys_siglist[key]);
}

void	gestion_winch(int key)
{
	(void)key;
	ft_fdprintf(1, "\nGerer le redimensionnemenmt de la fenetre !!!\n");
}

void	gestion_signal(void)
{
	int	i;

	i = 0;
	signal(SIGTSTP, gestion_susp);
	signal(SIGCONT, gestion_cont);
	signal(SIGINT, gestion_int);
	signal(SIGQUIT, gestion_int);
	signal(SIGWINCH, gestion_winch);
//	signal(SIGTTIN, gestion_susp);
	signal(SIGTTOU, gestion_susp);
	while (++i < NSIG)
	{
		if (i != SIGTSTP && i != SIGCONT && i != SIGINT && i != SIGQUIT && i != SIGWINCH && i != SIGTTOU && i != SIGTTIN)
//		if (i != SIGTSTP && i != SIGCONT && i != SIGINT && i != SIGQUIT && i != SIGWINCH)
			signal(i, gestion);

	}
}


