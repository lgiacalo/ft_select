/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 04:45:35 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/10/10 14:06:24 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <signal.h>

static t_dlist	*initialisation(int argc, char **argv)
{
	t_dlist	*args;

	term_init();
	args = args_init(argv, argc);
	env_init(args);
	return (args);
}

int				main(int argc, char **argv)
{
	int		key;
	t_dlist	*args;

	if (argc < 2)
		return (0);
	gestion_signal();
	args = initialisation(argc, argv);
	ft_putstr_fd(tgetstr("ti", NULL), 0);
	ft_putstr_fd(tgetstr("cl", NULL), 0);
	key = boucle(&args);
	ft_putstr_fd(tgetstr("te", NULL), 0);
	term_original();
	gestion_end(args, key);
	ft_dlstfree(&args, del);
	ft_fdprintf(1, "\n====== FIN ======\n"); //
	return (EXIT_SUCCESS);
}

/*
 **	Bug avec ft_printf mais pas avec ft_fdprintf
*/

/*
** 	Recalcule padding si modif taille fenetre !
*/
