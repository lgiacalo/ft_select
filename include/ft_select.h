/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 04:43:43 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/10/04 15:49:28 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft.h"
# include "ft_dlist.h"
# include "clavier.h"
# include <termcap.h>
# include <term.h>
# include <termios.h>
# include <sys/ioctl.h>

# define FT_SELECT(l) ((t_select *)(l->content))
# define FT_SELECT_NEXT(l) ((t_select *)(l->next->content))
# define FT_SELECT_PREV(l) ((t_select *)(l->prev->content))

typedef struct		s_term
{
	struct termios	term;
	struct termios	orig_term;
}					t_term;

typedef struct		s_select
{
	char			*str;
	int				selected;
}					t_select;

typedef struct		s_env
{
	struct winsize	w;
	int				nbr_args;
	int				padding;
	int				args_byline;
	int				curseur;
}					t_env;

void				error(char *msg, int restaure);

t_term				*term(void);
void				term_init(void);
void				term_original(void);

t_env				*env(void);
void				env_init(t_dlist *args);
void				ft_padding(t_dlist *args);

t_dlist				*args_init(char **argv, int argc);

int					boucle(t_dlist **args);
void				affichage_args(t_dlist *args);
void				del(void *content, size_t content_size);
void				aff_args_end(t_dlist *args);

void				gestion_fleche(int key);
void				gestion_space(t_dlist *args, int key);
void				gestion_delete(t_dlist **alst, int key);
void				gestion_end(t_dlist *args, int key);

void				gestion_signal(t_dlist *args);

void				ft_selectprint(t_select *lst);
void				ft_dlstprint(t_dlist *lst);
void				ft_envprint(void);

#endif
