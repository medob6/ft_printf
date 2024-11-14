/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printaddress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:03:41 by mbousset          #+#    #+#             */
/*   Updated: 2024/11/14 09:40:51 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	zero_cases_address(t_format flags, int f)
{
	int	width;

	width = 0;
	if (!flags.minus && !flags.zero_padding)
	{
		width = flags.width - flags.precision * !f - 1 * f - 2;
		print_pad(width, flags.zero_padding);
	}
	write(1, "0x", 2);
	print_pad(flags.precision, 1);
	if (f)
		write(1, "0", 1);
	if (flags.minus || flags.zero_padding)
	{
		width = flags.width - flags.precision * !f - 1 * f - 2;
		print_pad(width, flags.zero_padding);
	}
}

int	ft_print_address(unsigned long n, t_format flags)
{
	int	res;

	res = 0;
	if (flags.width || flags.precision != -1)
	{
		res = (flags.width - (flags.precision == 1));
	}
	if (n != 0)
		res += print_hex(n, flags);
	else
	{
		zero_cases_address(flags, flags.precision == -1);
		if (!flags.width && flags.precision == -1)
		{
			res = calc_res(flags, 0) + 2;
		}
		else
		{
			res += calc_res(flags, 0) + 2 * (flags.width <= flags.precision);
		}
	}
	return (res);
}
