/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 04:45:35 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/09/28 15:42:51 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <signal.h>

int	main(int argc, char **argv)
{
	t_select	*args;

	ft_fdprintf(1, "\n\t\tFT_SELECT : Debut ......\n\n");
	term_init();
	args = args_init(argv, argc);

	return (0);
}

/*
**	Bug avec ft_printf mais pas avec ft_fdprintf
*/
