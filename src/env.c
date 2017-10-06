/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 01:06:28 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/10/07 01:30:48 by lgiacalo         ###   ########.fr       */
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
	t_env	*envv;

	envv = env();
	if (ioctl(0, TIOCGWINSZ, &envv->w) == -1)
		error("Erreur : ioctl()", 1);
	ft_padding(args);
	envv->args_bycol = envv->w.ws_col / envv->padding;
	envv->curseur = 0;
	envv->args = args;
}
