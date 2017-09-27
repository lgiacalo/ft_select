/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 04:45:35 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/09/26 11:09:40 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		main(int argc, char **argv)
{
	ft_fdprintf(1, "\n\t\tFT_SELECT : Debut ......\n\n");

	t_select	*args;

	term_init();
	args = args_init(argv, argc);

	return (0);
}

/*
**
**	Bug avec ft_printf mais avec ft_fdprintf
**
*/
