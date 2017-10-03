/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 04:45:35 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/10/03 02:54:52 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		ft_envprint(void)
{
	t_env	*envv;

	envv = env();
	ft_fdprintf(1, "Structure Env :\n");
	ft_fdprintf(1, "Taille terminal	= LINES:%d--COLS:%d\n", envv->w.ws_row, envv->w.ws_col);
	ft_fdprintf(1, "\tNombre args	= [%d]\n", envv->nbr_args);
	ft_fdprintf(1, "\tPadding args	= [%d]\n\n", envv->padding);
	ft_printf("============================================\n");
	ft_printf("============================================\n\n");
}

void		ft_selectprint(t_select *lst)
{
	ft_fdprintf(1, "Structure Select :\n");
	ft_fdprintf(1, "\tStr	 	= [%s]\n", lst->str);
	ft_fdprintf(1, "\tSelectionne	= [%d]\n", lst->selected);
	ft_fdprintf(1, "\tIndice		= [%d]\n\n", lst->ind);
}

void		ft_dlstprint(t_dlist *lst)
{
	int	i;

	i = 0;
	ft_printf("Affichage double liste chainee : \n\n");
	while (lst)
	{
		if (i != FT_SELECT(lst)->ind)
			break;
		ft_fdprintf(1, "========= Maillon ===> [%0#x] ========\n", lst);
		ft_fdprintf(1, "Content		= [%x]\n", (unsigned int)(lst->content));
		ft_fdprintf(1, "Content_size	= [%zu]\n", lst->content_size);
		ft_fdprintf(1, "Prev 		= [%0#x]\n", (unsigned int)lst->prev);
		ft_fdprintf(1, "Next 		= [%0#x]\n", (unsigned int)lst->next);
		ft_selectprint(FT_SELECT(lst));
		lst = FT_DLST_NEXT(lst);
		i++;
	}
	ft_printf("============================================\n");
	ft_printf("============================================\n\n");
}
