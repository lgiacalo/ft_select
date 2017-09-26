/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 11:22:26 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/09/26 11:23:04 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	error(char *msg, int restaure)
{
	if (restaure)
		term_original();
	ft_fdprintf(STDERR_FILENO, "%s\n", msg);
	exit(EXIT_FAILURE);
}
