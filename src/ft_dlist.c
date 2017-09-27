/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 04:43:43 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/09/26 16:25:14 by lgiacalo         ###   ########.fr       */
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

void	ft_dlstdelone(t_dlist **alst, void (*del)(void *, size_t))
{
	if (alst)
	{
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = NULL;
	}
}

void	ft_dlstdel(t_dlist *alst, void(*del)(void *, size_t))
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
	while (temp)
	{
		*alst = temp;
		temp = (temp)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
	}
	*alst = NULL;
}
