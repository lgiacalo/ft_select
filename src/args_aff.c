/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_aff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 20:37:06 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/10/06 22:42:38 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	affichage_args(t_dlist *args)
{
	int	i;

	i = 0;
	ft_fdprintf(0, "\n");
	while (i < env()->nbr_args && args)
	{
		if (i == env()->curseur)
			ft_putstr_fd(AFF_SL, 0);
		if (FT_SELECT(args)->selected)
			ft_putstr_fd(AFF_VDI, 0);
		ft_fdprintf(0, "%s", FT_SELECT(args)->str);
		ft_putstr_fd(AFF_NOP, 0);
		ft_fdprintf(0, "%-*c",
				env()->padding - ft_strlen(FT_SELECT(args)->str), ' ');
		i++;
		args = FT_DLST_NEXT(args);
		if ((i % (env()->args_byline)) == 0)
			ft_fdprintf(0, "\n");
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
//	if (i > 0)
//		ft_fdprintf(1, "\n");
}
