/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialisation_term.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 06:36:20 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/09/25 07:48:28 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_error(char *msg, int restaure)
{
	if (restaure)
		ft_printf("Pensez a restaurer le terminal\n");
	ft_fdprintf(STDERR_FILENO, "%s\n", msg);
	exit(EXIT_FAILURE);
}

void	ft_initialisation_term(struct termios *term)
{
	char	*name_term;

	if ((name_term = getenv("TERM")) == NULL)
		ft_error("Variable \"TERM\": vide ou inexistant", 0);
	if (tgetent(NULL, name_term) <= 0)
		ft_error("tgetent: base de donnee introuvable ou term non defini", 0);
	if (tcgetattr(0, term) == -1)
		ft_error("tcgetattr: Erreur", 0);
}
