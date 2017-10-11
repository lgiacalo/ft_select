/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_aff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 20:37:06 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/10/11 12:15:35 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		putchar_select(int a)
{
	write(0, &a, 1);
	return (1);
}

void	affichage_args(t_dlist *args)
{
	int	i;
	int	k;
	int	col;

	i = 0;
	col = 0;
	k = 0;
	ft_putstr_fd(tgetstr("sc", NULL), 0);
	while (i < env()->nbr_args && args)
	{
		col = k * env()->padding;
		while (col && col--)
			tputs(tgetstr("nd", NULL), 1, putchar_select);
		(i == env()->curseur) ? ft_putstr_fd(AFF_SL, 0) : 0;
		(FT_SELECT(args)->selected) ? ft_putstr_fd(AFF_VDI, 0) : 0;
		ft_fdprintf(0, "%s", FT_SELECT(args)->str);
		ft_putstr_fd(AFF_NOP, 0);
		ft_fdprintf(0, "%-*c",
				env()->padding - ft_strlen(FT_SELECT(args)->str), ' ');
		i++;
		args = FT_DLST_NEXT(args);
		((i % (env()->w.ws_row)) == 0 && (k += 1)) ? tputs(tgetstr("rc", NULL),\
		1, putchar_select) : ft_fdprintf(0, "\n");
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
}
