/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 12:18:10 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/10/11 12:18:55 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_dlstdelone(t_dlist **alst, void (*del)(void *, size_t))
{
	if (alst && *alst)
	{
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = NULL;
	}
}

void	ft_dlstdel(t_dlist *alst, void (*del)(void *, size_t))
{
	if (alst->next)
		alst->next->prev = alst->prev;
	if (alst->prev)
		alst->prev->next = alst->next;
	ft_dlstdelone(&alst, del);
}

void	ft_dlstfree(t_dlist **alst, void (*del)(void *, size_t))
{
	t_dlist	*temp;

	if (!(*alst))
		return ;
	temp = *alst;
	while (temp && env()->nbr_args > 0)
	{
		*alst = temp;
		temp = (temp)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		env()->nbr_args--;
	}
	*alst = NULL;
}

/*
**	Fonction del : doit free les elements malloc de la structure select
** fonction ft_dlstfree bof bof
*/
