/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exemple_sigaction_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 15:07:57 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/09/28 15:38:55 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

void	gestionnaire(int numero)
{
	if (numero == SIGQUIT)
		fprintf(stdout, "\nSIGQUIT recu \n");
	if (numero == SIGINT)
		fprintf(stdout, "\nSIGINT recu \n");
	if (numero == SIGWINCH)
		fprintf(stdout, "Redimension de la fenetre !!!\n");
}

int		main(void)
{
	struct sigaction	action;

	action.sa_handler = gestionnaire;
	sigemptyset(&(action.sa_mask));
	action.sa_flags = 0;

	if (sigaction(SIGQUIT, &action, NULL)) //ctrl-"\"
	{
		fprintf(stdout, "Erreur %d\n", errno);
		exit(EXIT_FAILURE);
	}

	if (sigaction(SIGWINCH, &action, NULL))
	{
		fprintf(stdout, "Erreur %d\n", errno);
		exit(EXIT_FAILURE);
	}

	action.sa_flags = SA_RESTART | SA_RESETHAND;

	if (sigaction(SIGINT, &action, NULL)) //ctrl-C
	{
		fprintf(stdout, "Erreur %d\n", errno);
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		int i;
		fprintf(stdout, "appel read()\n");
		if (read(0, &i, sizeof(int)) < 0)
			if (errno == EINTR)
				fprintf(stdout, "EINTR \n");
	}
	return (EXIT_SUCCESS);
}
