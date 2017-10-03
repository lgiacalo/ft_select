/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 01:18:16 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/10/03 23:56:19 by lgiacalo         ###   ########.fr       */
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

void	del(void *content, size_t content_size)
{
	t_select	*tmp;

	(void)content_size;
	tmp = (t_select *)content;
	free(tmp);
}

void	ft_padding(t_dlist *args)
{
	int	i;
	int	len;

	i = -1;
	while (++i < env()->nbr_args)
	{
		len = ft_strlen(FT_SELECT(args)->str);
		if (env()->padding < len)
			env()->padding = len;
		args = args->next;
	}
	env()->padding++;
}
