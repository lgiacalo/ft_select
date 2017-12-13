/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boucle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 20:37:47 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/10/11 13:02:37 by lgiacalo         ###   ########.fr       */
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

void	gestion_bonus(t_dlist *args, int key)
{
	int	i;

	i = -1;
	if (key == 1 || key == 4)
	{
		while (++i < env()->nbr_args)
		{
			if (key == 1 && !FT_SELECT(args)->selected)
				FT_SELECT(args)->selected = 1;
			else if (key == 4 && FT_SELECT(args)->selected)
				FT_SELECT(args)->selected = 0;
			args = args->next;
		}
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
		ft_fdprintf(1, "Valeur touche [%d]\n", key);
		if (env()->args_byline != -1)
		{
			gestion_bonus(*args, key);
			gestion_clavier(args, key);
			ft_putstr_fd(tgetstr("cl", NULL), 0);
			affichage_args(*args);
		}
	}
	ft_putstr_fd(tgetstr("cl", NULL), 0);
	if (env()->nbr_args == 0)
		key = KEY_ESC;
	return (key);
}
