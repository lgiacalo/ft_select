/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 04:45:35 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/10/03 01:52:01 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <stdio.h>

void	affichage_args(t_dlist *args)
{
	int	i;
	int	len;
	
	(void)args;
	i = 0;
	while (i < env()->nbr_args)
	{
		len = env()->len_max;
		i++;
	}
}

int		boucle(t_dlist *args)
{
	int	key;

	(void)args;
	key = 0;
	while (key != 27 && key != 10)
	{
		affichage_args(args);
		key = 0;
		read(0, &key, sizeof(int));
		printf("\t[%d]\n", key);
	}
	return (key);
}

t_dlist	*initialisation(int argc, char **argv)
{
	t_dlist	*args;

	ft_fdprintf(1, "\n\t\tFT_SELECT : Debut ......\n\n");
	term_init();
	args = args_init(argv, argc);
	env_init(args);
	ft_dlstprint(args);
	ft_envprint();
	return (args);
}

int		main(int argc, char **argv)
{
	int		key;
	t_dlist	*args;

	args = initialisation(argc, argv);
	key = boucle(args);
	ft_fdprintf(1, "Sortie avec la touche [%d]\n", key);

	term_original();
	return (0);
}

/*
 **	Bug avec ft_printf mais pas avec ft_fdprintf
 */
