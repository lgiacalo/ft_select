/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialisation_term.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 06:36:20 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/09/28 16:32:15 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_term	*term(void)
{
	static t_term	t;

	return (&t);
}

int		verif_tcsetattr(termios term)
{
	int		i;
	termios	ret;

	i = -1;
	if (tcgetattr(STDIN_FILENO, &ret) == -1)
		error("tcgetattr: Erreur", 0);
	if (ret.c_iflag != term.c_iflag || ret.c_oflag != term.c_oflag\
		|| ret.c_cflag != term.c_cflag || ret.c_lflag != term.c_lflag\
		|| ret.c_ispeed != term.c_ispeed || ret.c_ospeed != term.c_ospeed)
		return (0);
	while (++i < NCCS)
		if (ret.c_cc[i] != term.c_cc[i])
			return (0);
	return (1);
}

void	term_original(void)
{
	if (term())
	{
		if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &term()->orig_term) == -1)
			error("Restauration terminal: Erreur", 0);
		if (!verif_tcsetattr(term()->orig_term))
			term_original();
	}
}

void	mode_non_canonique(void)
{
	t_term *t;

	t = term();
	t->term.c_lflag &= ~(ICANON);
	t->term.c_lflag &= ~(ECHO);
	if (tcsetattr(STDIN_FILENO, TCSANOW, &t->term) == -1)
		error("Erreur mode non canonique", 0);
	if (!verif_tcsetattr(t->term))
		mode_non_canonique();
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
	t->term = t->orig_term;
	mode_non_canonique();
}

/*
**	TODO:
**	Fonction tcsetattr : indique une reussite si au moins un changement effectue
**		Donc a re verifier avec tcgetattr !! voir livre linux
*/
