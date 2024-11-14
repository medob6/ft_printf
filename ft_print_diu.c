/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_diu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:11:14 by mbousset          #+#    #+#             */
/*   Updated: 2024/11/14 17:10:49 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_sign(int sign, t_format flags)
{
	if (sign)
		ft_putchar_fd('-', 1);
	else if (flags.plus && !sign)
		ft_putchar_fd('+', 1);
	else if (flags.space && !sign)
		ft_putchar_fd(' ', 1);
}

int	calc_width(t_format flags, int len, int sign)
{
	return (flags.width - len - (flags.space || flags.plus || sign)
		- (flags.precision > len) * (flags.precision - len));
}

void	before(t_format flags, int sign, int *len, int *count)
{
	if (flags.zero_padding)
		print_sign(sign, flags);
	if (!flags.minus && flags.width > *len && flags.width > flags.precision)
	{
		print_pad(calc_width(flags, *len, sign), flags.zero_padding);
		*count += calc_width(flags, *len, sign);
	}
	if (!flags.zero_padding)
		print_sign(sign, flags);
	while (*len < flags.precision)
	{
		ft_putchar_fd('0', 1);
		(*len)++;
	}
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
	before(flags, sign, &len, &count);
	if (flags.precision == 0 && n == 0)
	{
		res = "";
		count -= 1;
	}
	ft_putstr_fd(res, 1);
	if (flags.minus && flags.width > len)
	{
		print_pad(calc_width(flags, len, sign), flags.zero_padding);
		count += calc_width(flags, len, sign);
	}
	free(res);
	return (count + len);
}
