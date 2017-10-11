/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 04:43:43 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/10/11 12:18:51 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_dlist	*ft_dlstnew(void const *content, size_t content_size)
{
	t_dlist	*new;

	new = NULL;
	new = (t_dlist *)ft_memalloc(sizeof(t_dlist) * 1);
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		new->content = ft_memalloc(content_size);
		ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
	}
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_dlstadd(t_dlist **alst, t_dlist *new)
{
	if (!new)
		return ;
	new->next = *alst;
	if (*alst)
		(*alst)->prev = new;
	*alst = new;
}

void	ft_dlstadd_end(t_dlist **alst, t_dlist *new)
{
	t_dlist	*temp;

	temp = *alst;
	if (!new)
		return ;
	if (temp)
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
	}
	else
		*alst = new;
}

t_dlist	*ft_dlstat(t_dlist *lst, unsigned int nbr)
{
	unsigned int	i;

	i = 0;
	while (i < nbr && lst)
	{
		lst = lst->next;
		i++;
	}
	if (i == nbr && lst)
		return (lst);
	return (NULL);
}
