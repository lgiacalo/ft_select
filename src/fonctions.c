/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 01:18:16 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/10/03 02:54:34 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

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


