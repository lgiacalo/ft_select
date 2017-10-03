/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 04:45:35 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/10/03 23:56:54 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

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
	args = initialisation(argc, argv);
	key = boucle(&args);
	term_original();
	gestion_end(args, key);
	ft_dlstfree(&args, del);
	return (EXIT_SUCCESS);
}

/*
 **	Bug avec ft_printf mais pas avec ft_fdprintf
*/

/*
** 	Recalcule padding si modif taille fenetre !
*/
