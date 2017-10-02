/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 04:43:43 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/10/03 01:31:52 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft.h"
# include "ft_dlist.h"
# include <termcap.h>
# include <term.h>
# include <termios.h>

# define FT_SELECT(l) ((t_select *)(l->content))
# define FT_SELECT_NEXT(l) ((t_select *)(l->next->content))
# define FT_SELECT_PREV(l) ((t_select *)(l->prev->content))

typedef struct termios	termios;

typedef struct		s_term
{
	termios			term;
	termios			orig_term;
}					t_term;

typedef struct		s_select
{
	char			*str;
	int				selected;
	int				ind;
}					t_select;

typedef struct		s_env
{
	int				nbr_args;
	int				len_max;
}					t_env;

void				error(char *msg, int restaure);

t_term				*term(void);
void				term_init(void);
void				term_original(void);

t_env				*env(void);
void				env_init(t_dlist *args);

void				ft_len_max_args(t_dlist *args);
t_dlist				*args_init(char **argv, int argc);

void				ft_selectprint(t_select *lst);
void				ft_dlstprint(t_dlist *lst);
void				ft_envprint(void);

#endif
