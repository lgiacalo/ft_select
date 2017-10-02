/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 04:45:35 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/10/02 21:27:32 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_select	*args_init(char **argv, int argc)
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
	ft_dlstprint(alst);
	// faire une liste circlaire !!
	return (NULL);
}
