/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 04:45:35 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/10/10 16:35:37 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		ft_envprint(void)
{
	t_env	*envv;

	envv = env();
	ft_fdprintf(1, "Structure Env :\n");
	ft_fdprintf(1, "Taille terminal	= LINES:%d--COLS:%d\n",
			envv->w.ws_row, envv->w.ws_col);
	ft_fdprintf(1, "\tNombre args	= [%d]\n", envv->nbr_args);
	ft_fdprintf(1, "\tPadding args	= [%d]\n\n", envv->padding);
	ft_fdprintf(1, "\tArgs_byline	= [%d]\n\n", envv->args_byline);
	ft_printf("============================================\n");
	ft_printf("============================================\n\n");
}

void		ft_selectprint(t_select *lst)
{
	ft_fdprintf(1, "Structure Select :\n");
	ft_fdprintf(1, "\tStr	 	= [%s][%d]\n", lst->str, ft_strlen(lst->str));
	ft_fdprintf(1, "\tSelectionne	= [%d]\n", lst->selected);
}

void		ft_termprint(struct termios term)
{
	ft_fdprintf(2, "Lflags = [%d]\n", term.c_lflag);
	ft_fdprintf(2, "Iflags = [%d]\n", term.c_iflag);
	ft_fdprintf(2, "Oflags = [%d]\n", term.c_oflag);
	ft_fdprintf(2, "Cflags = [%d]\n", term.c_cflag);
}

void		ft_dlstprint(t_dlist *lst)
{
	int	i;

	i = 0;
	ft_printf("Affichage double liste chainee : \n\n");
	while (lst)
	{
		if (i > env()->nbr_args)
			break ;
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
