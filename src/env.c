/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 01:06:28 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/10/10 16:38:20 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_env	*env(void)
{
	static t_env	env;

	return (&env);
}

void	env_init(t_dlist *args)
{
	t_env	*e;

	e = env();
	if (ioctl(0, TIOCGWINSZ, &e->w) == -1)
		error("Erreur : ioctl()", 1);
	ft_padding(args);
//	e->args_byline = e->w.ws_col / e->padding;
	e->args_byline = e->nbr_args / e->w.ws_row;
//	if (!(e->nbr_args % e->w.ws_row))
//		e->args_byline++;
//	if (e->w)
	e->curseur = 0;
	e->args = args;
	ft_envprint();
}
