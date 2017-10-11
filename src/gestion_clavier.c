/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_clavier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 22:36:27 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/10/11 12:16:18 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	gestion_end(t_dlist *args, int key)
{
	if (key == KEY_RETURN)
		aff_args_end(args);
}

void	gestion_fleche(int key)
{
	t_env	*e;

	e = env();
	if (key == KEY_FR)
		e->curseur += ((e->curseur + e->w.ws_row) < e->nbr_args)
			? e->w.ws_row : 0;
	else if (key == KEY_FL)
		e->curseur -= ((e->curseur - e->w.ws_row) < 0) ? 0 : e->w.ws_row;
	else if (key == KEY_FU)
		e->curseur = ((e->curseur - 1) >= 0) ? e->curseur - 1 : e->nbr_args - 1;
	else if (key == KEY_FD)
		e->curseur = ((e->curseur + 1) > (e->nbr_args - 1))
			? 0 : (e->curseur + 1);
}

void	gestion_space(t_dlist *args, int key)
{
	t_dlist	*tmp;

	if (key == KEY_SPACE)
	{
		tmp = ft_dlstat(args, env()->curseur);
		if (!FT_SELECT(tmp)->selected)
			FT_SELECT(tmp)->selected = 1;
		else
			FT_SELECT(tmp)->selected = 0;
		gestion_fleche(KEY_FD);
	}
}

void	gestion_delete(t_dlist **alst, int key)
{
	t_dlist	*tmp;

	if (key == KEY_DELETE)
	{
		env()->nbr_args--;
		tmp = ft_dlstat(*alst, env()->curseur);
		if (tmp == *alst)
			*alst = tmp->next;
		ft_dlstdel(tmp, del);
		if (env()->curseur > (env()->nbr_args - 1))
			env()->curseur = env()->nbr_args - 1;
	}
}
