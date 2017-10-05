/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 15:48:29 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/10/05 19:32:15 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

extern const char * const sys_siglist[];

void	gestion(int key)
{
	ft_fdprintf(2, "\n%ld a recu le signal %d (%s)   [%d]\n",
			(long)getpid(), key, sys_siglist[key], ttyslot());
}

void	gestion_susp(int key)
{
	(void)key;
//	if (!isatty(1))
//		return ;
	ft_fdprintf(2, "\nJe suis dans SIGTSTP [%d][%d]\n", ttyslot, key);
	if (key == SIGTTOU)
	{
		ft_fdprintf(2, "Je suis dans susp avec sigttou\n");
		return ;
	}
	if (!isatty(0))
	{
		ft_fdprintf(2, "\n je suis dans isatty susp\n");
		return ;
	}
	ioctl(0, TIOCSTI, "\032");
	term_original();
	signal(SIGTSTP, SIG_DFL);
//	signal(SIGTTOU, gestion_susp);
//	signal(SIGTTIN, gestion_susp);
}

void	gestion_out(int key)
{

	ft_fdprintf(2, "\nJe suis dans SIGTOUTT [%d][%d]\n", ttyslot(), key);
	(void)key;
	gestion_susp(SIGTSTP);
//	signal(SIGTSTP, SIG_DFL);
//	ioctl(0, TIOCSTI, "\032");
}

void	gestion_cont(int key)
{
	(void)key;
	if (!isatty(0))
	{
		ft_fdprintf(2, "\n je suis dans isatty cont\n");
		return ;
	}
	ft_fdprintf(2, "\nJe suis dans SIGCONT [%d][%d]\n", ttyslot(), key);
//	signal(SIGTTIN, SIG_IGN);
//	if (key != SIGTTOU)
//	{
		mode_non_canonique();
		affichage_args(env()->args);
//	}
//	signal(SIGTSTP, gestion_susp);
}

void	gestion_int(int key)
{
	(void)key;
	ft_fdprintf(2, "\nJe suis dans SIGINT [%d]\n", key);
	term_original();
	gestion_end(env()->args, 27);
	ft_dlstfree(&(env()->args), del);
	ft_fdprintf(2, "\n====== FIN 2 ======\n"); //
	exit(EXIT_SUCCESS);	
}

void	gestion_winch(int key)
{
	(void)key;
	ft_fdprintf(2, "\nGerer le redimensionnemenmt de la fenetre !!!\n");
}

void	gestion_signal(void)
{
	int	i;

	i = 0;
	signal(SIGTSTP, gestion_susp);
	signal(SIGCONT, gestion_cont);
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTTOU, gestion_out);

	signal(SIGWINCH, gestion_winch);

	signal(SIGINT, gestion_int);
	signal(SIGQUIT, gestion_int);
	signal(SIGHUP, gestion_int);
	signal(SIGILL, gestion_int);
	signal(SIGTRAP, gestion_int);
	signal(SIGABRT, gestion_int);
	signal(SIGFPE, gestion_int);
	signal(SIGKILL, gestion_int);
	signal(SIGBUS, gestion_int);
	signal(SIGSEGV, gestion_int);
	signal(SIGSYS, gestion_int);
	signal(SIGPIPE, gestion_int);
	signal(SIGALRM, gestion_int);
	signal(SIGTERM, gestion_int);
	signal(SIGSTOP, gestion_int);
	signal(SIGUSR1, gestion_int);
	signal(SIGUSR2, gestion_int);
}
