/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 04:43:43 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/09/26 16:25:14 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft.h"
# include <termcap.h>
# include <term.h>
# include <termios.h>

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
}					t_select;

void				error(char *msg, int restaure);

t_term				*term(void);
void				term_init(void);
void				term_original(void);

t_select			*args_init(char **argv, int argc);

#endif
