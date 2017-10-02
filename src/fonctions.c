/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 01:18:16 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/10/03 01:45:30 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_len_max_args(t_dlist *args)
{
	int	i;
	int	len;

	i = -1;
	while (++i < env()->nbr_args)
	{
		len = ft_strlen(FT_SELECT(args)->str);
		if (env()->len_max < len)
			env()->len_max = len;
		args = args->next;
	}
	env()->len_max++;
}


