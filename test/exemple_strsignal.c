/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exemple_strsignal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 13:25:00 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/09/28 15:07:37 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

#ifndef _POSIX_REALTIME_SIGNALS
	#error "Pas de signaux temps reel disponibles"
#endif

int	main(void)
{
	int	i;

	fprintf(stdout, "strsignal() : \n");
	for (i = 1; i < NSIG; i++)
		fprintf(stdout, "%s\n", strsignal(i));

	fprintf(stdout, "\nsys_siglist[] : \n");
	for (i = 1; i < NSIG ; i++)
		fprintf(stdout, "%d : %s\n", i, sys_siglist[i]);
	return (EXIT_SUCCESS);
}
