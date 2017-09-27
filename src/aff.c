/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 04:45:35 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/09/26 11:09:40 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		ft_selectprint(t_select *lst)
{
	ft_fdprintf(1, "Structure Select :\n");
	ft_fdprintf(1, "\tStr	 	= [%s]\n", lst->str);
	ft_fdprintf(1, "\tSelectionne	= [%d]\n\n", lst->selected);
}

void		ft_dlstprint(t_dlist *lst)
{
	ft_printf("Affichage double liste chainee : \n\n");
	while (lst)
	{
		ft_fdprintf(1, "========= Maillon ===> [%0#x] ========\n", lst);
		ft_fdprintf(1, "Content		= [%x]\n", (unsigned int)(lst->content));
		ft_fdprintf(1, "Content_size	= [%zu]\n", lst->content_size);
		ft_fdprintf(1, "Prev 		= [%0#x]\n", (unsigned int)lst->prev);
		ft_fdprintf(1, "Next 		= [%0#x]\n", (unsigned int)lst->next);
		ft_selectprint(FT_SELECT(lst));
		lst = FT_DLST_NEXT(lst);
	}
	ft_printf("==========================================\n");
}
