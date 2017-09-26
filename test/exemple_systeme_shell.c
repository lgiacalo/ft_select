/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exemple_systeme_shell.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 14:58:06 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/09/26 14:59:41 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	char	ligne[MAX_CANON];

	while (1)
	{
		fprintf(stderr, "-> ");
		if (fgets(ligne, MAX_CANON, stdin) == NULL)
			break;
		system(ligne);
	}
	return (0);
}
