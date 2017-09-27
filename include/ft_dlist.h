/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 04:43:43 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/09/26 16:25:14 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DLIST_H
# define FT_DLIST_H

# include "ft_select.h"

typedef struct		s_dlist
{
	void			*content;
	size_t			content_size;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

# define FT_DLSTX_PREV(l, x) ((x *)(((l)->prev)->content))
# define FT_DLSTX_NEXT(l, x) ((x *)(((l)->next)->content))


t_dlist				*ft_dlstnew(void const *content, size_t content_size);
void				ft_dlstadd(t_dlist **alst, t_dlist *new);
void				ft_dlstadd_end(t_dlist **alst, t_dlist *new);
t_dlist				*ft_dlstat(t_dlist *lst, unsigned int nbr);
void				ft_dlstdelone(t_dlist **alst, void (*del)(void *, size_t));
void				ft_dlstdel(t_dlist *alst, void(*del)(void *, size_t));
void				ft_dlstfree(t_dlist **alst, void (*del)(void *, size_t));

//# define FT_DLSTX_PREV(l, x) ((x*)(l)->head.prev)
//# define FT_DLSTX_NEXT(l, x) ((x*)(l)->head.next)
//# define FT_DLSTS_PREV(l) (FT_DLSTX_PREV(l, t_dlists))
//# define FT_DLSTS_NEXT(l) (FT_DLSTX_NEXT(l, t_dlists))

#endif
