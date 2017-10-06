/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 15:48:29 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/10/07 01:22:23 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	gestion_int(int key)
{
	(void)key;

	ft_putstr_fd(tgetstr("te", NULL), 0);
	term_original();
	gestion_end(env()->args, 27);
	ft_dlstfree(&(env()->args), del);
	exit(EXIT_SUCCESS);
}

void	gestion_susp(int key)
{
	(void)key;
	ft_putstr_fd(tgetstr("te", NULL), 0);
	term_original();
	ioctl(0, TIOCSTI, "\032");
	signal(SIGTSTP, SIG_DFL);
}

void	gestion_cont(int key)
{
	(void)key;
	signal(SIGTSTP, gestion_susp);
	term_init();
	ft_putstr_fd(tgetstr("ti", NULL), 0);
	affichage_args(env()->args);
}

void	gestion_winch(int key)
{
	(void)key;
//	ft_fdprintf(0, "\nGerer le redimensionnemenmt de la fenetre !!!\n");
}

void	gestion_signal(void)
{
	signal(SIGTSTP, gestion_susp);
	signal(SIGCONT, gestion_cont);
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
