/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 04:45:35 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/10/03 16:00:50 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_dlist	*args_init(char **argv, int argc)
{
	t_select	new;
	t_dlist		*alst;
	t_dlist		*maillon;
		int			i;

		i = 0;
		alst = NULL;
		new.selected = 0;
		while (++i < argc)
		{
			new.ind = i - 1;
			new.str = argv[i];
			new.selected = 0;
			maillon = ft_dlstnew((void *)(&new), sizeof(t_select));
		ft_dlstadd_end(&alst, maillon);
	}
	env()->nbr_args = i - 1;
	if (argc > 1)
	{
		maillon->next = alst;
		alst->prev = maillon;
	}
	return (alst);
}
