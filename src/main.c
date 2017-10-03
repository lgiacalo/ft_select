/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 04:45:35 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/10/03 23:14:19 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_dlist	*initialisation(int argc, char **argv)
{
	t_dlist	*args;

	ft_fdprintf(1, "\n\t\tFT_SELECT : Debut ......\n\n");
	term_init();
	args = args_init(argv, argc);
	env_init(args);
//	ft_dlstprint(args);
//	ft_envprint();
	return (args);
}

int		main(int argc, char **argv)
{
	int		key;
	t_dlist	*args;

	if (argc < 2)
		return (0);
	args = initialisation(argc, argv);
	key = boucle(&args);
	ft_fdprintf(1, "Sortie avec la touche [%d]\n", key);
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
