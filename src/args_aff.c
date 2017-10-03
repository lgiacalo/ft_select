/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_aff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 20:37:06 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/10/03 23:51:02 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	affichage_args(t_dlist *args)
{
	int	i;

	i = 0;
	ft_fdprintf(1, "\n");
	while (i < env()->nbr_args && args)
	{
		if (i == env()->curseur)
			ft_putstr(AFF_SL);
		if (FT_SELECT(args)->selected)
			ft_putstr(AFF_VDI);
		ft_fdprintf(1, "%s", FT_SELECT(args)->str);
		ft_putstr("\e[0m");
		ft_fdprintf(1, "%-*c",
				env()->padding - ft_strlen(FT_SELECT(args)->str), ' ');
		i++;
		args = FT_DLST_NEXT(args);
		if ((i % (env()->args_byline)) == 0)
			ft_fdprintf(1, "\n");
	}
}

void	aff_args_end(t_dlist *args)
{
	int		i;
	t_dlist	*tmp;

	tmp = args;
	i = 0;
	while (i < env()->nbr_args && tmp)
	{
		if (FT_SELECT(tmp)->selected)
			ft_fdprintf(1, "%s ", FT_SELECT(tmp)->str);
		tmp = tmp->next;
		i++;
	}
	if (i > 0)
		ft_fdprintf(1, "\n");
}
