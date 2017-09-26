/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 04:43:43 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/09/26 11:23:12 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft.h"
# include <curses.h>
# include <term.h>
# include <termios.h>

typedef struct termios	termios;

typedef struct	s_term
{
	termios		term;
	termios		orig_term;
}				t_term;

void		error(char *msg, int restaure);

t_term		*term(void);
void		term_init(void);
void		term_original(void);

#endif
