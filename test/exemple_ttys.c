/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exemple_ttys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 15:40:57 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/09/28 15:42:44 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int		main(void)
{
	int	i = ttyslot();
	ft_fdprintf(1, "Retour fonction ttyslot : [%d]\n", i);
	char	*name = ttyname(1);
	ft_fdprintf(1, "Nom du peripherique [%s]\n", name);
	ft_fdprintf(1, "Isatty = [%d]\n", isatty(1));

	ft_fdprintf(1, "Valeur de NSIG = [%d]\n", NSIG);
	ft_fdprintf(1, "_NSIG = [%d]\n", _NSIG);
	return (EXIT_SUCCESS);
}
