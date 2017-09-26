/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 14:39:45 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/09/26 14:43:09 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

int	main(void)
{
	struct termios	terminal;
	int				i;

	fprintf(stdout, "FLUSH, dans 5 secondes\n");
	sleep(5);
	fprintf(stdout, "FLUSH !\n");
	if (tcgetattr(STDIN_FILENO, &terminal) == 0)
		tcsetattr(STDIN_FILENO, TCSAFLUSH, &terminal);
	while ((i = fgetc(stdin)) != EOF)
		fprintf(stdout, "%02X ", i);
	return (EXIT_SUCCESS);
}
