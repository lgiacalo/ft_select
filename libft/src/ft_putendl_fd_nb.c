/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd_nb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 23:14:58 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/02/03 21:18:07 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_putendl_fd_nb(char const *s, int fd)
{
	size_t	i;

	if (!s)
		return (-1);
	i = ft_strlen(s);
	write(fd, s, i);
	write(fd, "\n", 1);
	return (i + 1);
}
