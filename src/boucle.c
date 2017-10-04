/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boucle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 20:37:47 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/10/04 17:06:41 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		boucle(t_dlist **args)
{
	int	key;

	key = 0;
	while (key != KEY_RETURN && key != KEY_ESC && env()->nbr_args > 0)
	{
		affichage_args(*args);
		key = 0;
		read(0, &key, sizeof(int));
		ft_fdprintf(1, "\n[%d]\n", key); ///
		gestion_fleche(key);
		gestion_space(*args, key);
		gestion_delete(args, key);
	}
	if (env()->nbr_args == 0)
		key = KEY_ESC;
	return (key);
}
