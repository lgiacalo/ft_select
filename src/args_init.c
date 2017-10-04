/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 04:45:35 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/10/04 15:45:23 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	ft_dlst_circulaire(t_dlist *alst, t_dlist *maillon)
{
	maillon->next = alst;
	alst->prev = maillon;
}

static t_dlist	*ft_new_maillon(t_dlist **alst, char *argv)
{
	t_select	new;
	t_dlist		*maillon;

	new.str = argv;
	new.selected = 0;
	maillon = ft_dlstnew((void *)(&new), sizeof(t_select));
	ft_dlstadd_end(alst, maillon);
	return (maillon);
}

t_dlist		*args_init(char **argv, int argc)
{
	t_dlist		*alst;
	t_dlist		*maillon;
	int			i;

	i = 0;
	alst = NULL;
	while (++i < argc)
	{
		maillon = ft_new_maillon(&alst, argv[i]);
	}
	env()->nbr_args = i - 1;
	(argc > 1) ? ft_dlst_circulaire(alst, maillon) : 0;
	return (alst);
}
