/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 06:52:51 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/02/23 21:33:50 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_len_str(t_flags *flags, int len_str)
{
	int	ret;

	ret = len_str;
	if ((flags->prec) && (flags->prec_val < ret))
		ret = flags->prec_val;
	else
		flags->prec_val = ret;
	if (flags->width && (flags->width_val > ret))
	{
		flags->width_val -= ret;
		ret += flags->width_val;
	}
	else
		flags->width_val = 0;
	return (ret);
}

int			ft_putwstr_len(wchar_t *str, int len, int ok)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (*str)
	{
		if ((i += ft_wcharlen_o(*str)) <= len)
		{
			if (ok == 1)
				ft_putwchar(*str);
		}
		else
			return (i - ft_wcharlen_o(*str));
		str++;
	}
	return (i);
}

static int	ft_conv_wchar(wchar_t *str, t_flags *flags)
{
	char	*str_ret;
	int		ret;
	int		len_str;

	len_str = ft_wstrlen_o(str);
	ret = ft_len_str(flags, len_str);
	if (flags->width_val > 0 && ((flags->width_val +\
		(flags->prec_val - ft_putwstr_len(str, flags->prec_val, 0)) > 0)))
		flags->width_val += (flags->prec_val\
		- ft_putwstr_len(str, flags->prec_val, 0));
	if (!(str_ret = ft_strnew((size_t)(flags->width_val))))
		return (EXIT_FAILURE);
	ft_memset(str_ret, ' ', flags->width_val);
	(flags->att & ATT_MINUS) ? ret = ft_putwstr_len(str, flags->prec_val, 1)\
									: 0;
	(flags->att & ATT_MINUS) ? ft_putstr(str_ret) : 0;
	if (!(flags->att & ATT_MINUS))
	{
		(flags->att & ATT_ZERO) ? ft_memset(str_ret, '0', flags->width_val) : 0;
		ft_putstr(str_ret);
		ret = ft_putwstr_len(str, flags->prec_val, 1);
	}
	ft_memdel((void **)&str_ret);
	return ((flags->width_val + ret));
}

static int	ft_conv_char(char *str, t_flags *flags)
{
	char	*str_ret;
	int		ret;
	int		len_str;

	len_str = ft_strlen(str);
	ret = ft_len_str(flags, len_str);
	if (!(str_ret = ft_strnew((size_t)ret)))
		return (EXIT_FAILURE);
	ft_memset(str_ret, ' ', ret);
	ret = (flags->att & ATT_MINUS) ? 0 : (ret - flags->prec_val);
	ft_strncpy((str_ret + ret), str, flags->prec_val);
	((flags->att & ATT_ZERO)) ? ft_memset((str_ret), '0', flags->width_val) : 0;
	ret = ft_putstr(str_ret);
	ft_memdel((void **)&str_ret);
	return (ret);
}

int			ft_conv_s(unsigned long int nbr, t_flags *flags)
{
	int		ret;

	if ((flags->conv & CONV_UP_S || ((flags->conv & CONV_S)\
			&& (flags->len & LEN_L))) && nbr != 0)
		ret = ft_conv_wchar((wchar_t *)nbr, flags);
	else
		ret = (nbr == 0) ? ft_conv_char("(null)", flags)\
			: ft_conv_char((char *)nbr, flags);
	return (ret);
}
