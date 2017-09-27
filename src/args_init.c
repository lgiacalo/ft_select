/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 04:45:35 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/09/26 11:09:40 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_select	*args_init(char **argv, int argc)
{
	t_select	new;
	t_dlist		*alst;
	t_dlist		*mail;
	int			i;

	i = 0;
	alst = NULL;
	new.selected = 0;
	while (++i < argc)
	{
		new.str = argv[i];
		mail = ft_dlstnew((void *)(&new), sizeof(t_dlist *));
		ft_dlstadd_end(&alst, mail);
	}
	ft_dlstprint(alst);
	return (NULL);
}
