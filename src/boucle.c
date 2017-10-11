/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boucle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 20:37:47 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/10/11 12:14:42 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	window_sosmall(void)
{
	int	i;

	i = 0;
	ft_putstr_fd(tgetstr("cl", NULL), 0);
	ft_fdprintf(0, "Fenetre trop petite !!");
	tputs(tgetstr("rc", NULL), 1, putchar_select);
	while (i < 22)
	{
		tputs(tgetstr("nd", NULL), 1, putchar_select);
		i++;
	}
}

int		boucle(t_dlist **args)
{
	int	key;

	key = 0;
	affichage_args(*args);
	while (key != KEY_RETURN && key != KEY_ESC && env()->nbr_args > 0)
	{
		key = 0;
		read(0, &key, sizeof(int));
		if (env()->args_byline != -1)
		{
			gestion_fleche(key);
			gestion_space(*args, key);
			gestion_delete(args, key);
			ft_putstr_fd(tgetstr("cl", NULL), 0);
			affichage_args(*args);
		}
	}
	ft_putstr_fd(tgetstr("cl", NULL), 0);
	if (env()->nbr_args == 0)
		key = KEY_ESC;
	return (key);
}
