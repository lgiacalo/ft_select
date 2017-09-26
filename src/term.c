/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialisation_term.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 06:36:20 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/09/26 11:18:51 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_term	*term(void)
{
	static t_term	t;
	return (&t);
}

void	term_original(void)
{
	if(term())
		if (tcsetattr(STDIN_FILENO, 0, &term()->orig_term) == -1)
			error("Restauration terminal: Erreur", 0);
}

void	term_init(void)
{
	char	*name_term;
	t_term	*t;

	t = term();
	if ((name_term = getenv("TERM")) == NULL)
		error("Variable \"TERM\": vide ou inexistant", 0);
	if (tgetent(NULL, name_term) <= 0)
		error("tgetent: base de donnee introuvable ou term non defini", 0);
	if (tcgetattr(STDIN_FILENO, &t->orig_term) == -1)
		error("tcgetattr: Erreur", 0);
	t->orig_term = t->term;
}

/*
**	TODO:
**	Fonction tcsetattr : indique une reussite si au moins un changement effectue
**		Donc a re verifier avec tcgetattr !! voir livre linux
**
*/
