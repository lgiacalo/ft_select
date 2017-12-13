/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialisation_term.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 06:36:20 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/10/11 12:16:43 by lgiacalo         ###   ########.fr       */
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
	if (tcsetattr(STDIN_FILENO, TCSANOW, &term()->orig_term) == -1)
		error("Restauration terminal: Erreur", 0);
}

void	mode_non_canonique(void)
{
	t_term *t;

	t = term();
	t->term.c_lflag &= ~(ICANON);
	t->term.c_lflag &= ~(ECHO);
	t->term.c_cc[VMIN] = 1;
	t->term.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &t->term);
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
	if (tcgetattr(STDIN_FILENO, &t->term) == -1)
		error("tcgetattr: Erreur", 0);
	mode_non_canonique();
}
