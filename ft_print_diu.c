/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_diu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:11:14 by mbousset          #+#    #+#             */
/*   Updated: 2024/11/16 10:26:32 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_sign(int sign, t_format flags)
{
	if (sign)
	{
		if (ft_putchar('-') == -1)
			return (-1);
	}
	else if (flags.plus && !sign)
	{
		if (ft_putchar('+') == -1)
			return (-1);
	}
	else if (flags.space && !sign)
	{
		if (ft_putchar(' ') == -1)
			return (-1);
	}
	return (0);
}

int	calc_width(t_format flags, int len, int sign)
{
	return (flags.width - len - (flags.space || flags.plus || sign)
		- (flags.precision > len) * (flags.precision - len));
}

int	before(t_format flags, int sign, int *len, int *count)
{
	if (flags.zero_padding)
	{
		if (print_sign(sign, flags) == -1)
			return (-1);
	}
	if (!flags.minus && flags.width > *len && flags.width > flags.precision)
	{
		if (print_pad(calc_width(flags, *len, sign), flags.zero_padding) == -1)
			return (-1);
		*count += calc_width(flags, *len, sign);
	}
	if (!flags.zero_padding)
	{
		if (print_sign(sign, flags) == -1)
			return (-1);
	}
	while (*len < flags.precision)
	{
		if (ft_putchar('0') == -1)
			return (-1);
		(*len)++;
	}
	return (0);
}

int	ft_print_diu(long n, t_format flags)
{
	int		len;
	char	*res;
	int		count;
	int		sign;

	sign = (n < 0);
	count = (flags.space || flags.plus || sign);
	res = ft_itoa(n * (-sign) + n * (!sign));
	len = ft_strlen(res);
	if (before(flags, sign, &len, &count) == -1)
		return (free(res), -1);
	if (flags.precision == 0 && n == 0)
	{
		res = "";
		count -= 1;
	}
	if (ft_putstr(res) == -1)
		return (free(res), -1);
	if (flags.minus && flags.width > len)
	{
		if (print_pad(calc_width(flags, len, sign), flags.zero_padding) == -1)
			return (free(res), -1);
		count += calc_width(flags, len, sign);
	}
	return (free(res), (count + len));
}
