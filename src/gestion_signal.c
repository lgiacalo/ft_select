/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 15:48:29 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/10/05 16:03:36 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

extern const char * const sys_siglist[];

void	gestion_susp(int key)
{
	(void)key;
//	if (!isatty(1))
//		return ;
	if (!isatty(0))
	{
		ft_fdprintf(2, "\n je suis dans isatty susp\n");
		return ;
	}
	ft_fdprintf(2, "\nJe suis dans SIGTSTP [%d][%d]\n", ttyslot, key);
	term_original();
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, "\032");
//	term_original();
}

void	gestion_out(int key)
{

	ft_fdprintf(2, "\nJe suis dans SIGTOUTT [%d][%d]\n", ttyslot(), key);
	(void)key;
//	signal(SIGTSTP, SIG_DFL);
//	ioctl(0, TIOCSTI, "\032");
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, "\032");

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
	if (verif_tcsetattr(term()->orig_term))
	{
		ft_fdprintf(2, "je suis dans la verif de cont\n");
		mode_non_canonique();
		affichage_args(env()->args);
	}
	signal(SIGTTOU, gestion_susp);
	signal(SIGTSTP, gestion_susp);
}

void	gestion_int(int key)
{
	(void)key;
	ft_fdprintf(2, "\nJe suis dans SIGINT\n");
	term_original();
	gestion_end(env()->args, 27);
	ft_dlstfree(&(env()->args), del);
	ft_fdprintf(2, "\n====== FIN 2 ======\n"); //
	exit(EXIT_SUCCESS);	
}

void	gestion(int key)
{
	ft_fdprintf(2, "\n%ld a recu le signal %d (%s)   [%d]\n",
			(long)getpid(), key, sys_siglist[key], ttyslot());
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
	signal(SIGTTOU, gestion_susp);
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
