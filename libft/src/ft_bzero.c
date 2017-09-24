/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 02:23:24 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/12/19 22:40:32 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/../include/libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t i;

	i = -1;
	while (++i < n)
		*(unsigned char*)(s + i) = '\0';
}
