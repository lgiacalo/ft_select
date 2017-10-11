/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 01:06:28 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/10/11 12:14:09 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_env	*env(void)
{
	static t_env	env;

	return (&env);
}

void	env_windows(void)
{
	t_env	*e;
	int		nbr;

	e = env();
	if (ioctl(0, TIOCGWINSZ, &e->w) == -1)
		error("Erreur : ioctl()", 1);
	e->args_byline = e->nbr_args / e->w.ws_row;
	nbr = ((e->w.ws_col / e->padding) * e->w.ws_row);
	if (((e->w.ws_col / e->padding) * e->w.ws_row) < e->nbr_args)
		e->args_byline = -1;
}

void	env_init(t_dlist *args)
{
	t_env	*e;

	e = env();
	ft_padding(args);
	env_windows();
	e->curseur = 0;
	e->args = args;
}
